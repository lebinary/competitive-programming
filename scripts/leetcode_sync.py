#!/usr/bin/env python3
"""Download LeetCode submissions into this repo, incrementally.

Credentials come from the environment (or a .env file at the repo root):

    LEETCODE_SESSION   the LEETCODE_SESSION cookie
    LEETCODE_CSRF      the csrftoken cookie

Both are read from your browser's cookies for leetcode.com. The session token
expires after about two weeks, at which point you re-copy it.

Downloaded code lands in leetcode/<id>/submissions/ and never touches files you
wrote by hand.
"""

from __future__ import annotations

import argparse
import json
import os
import random
import re
import sys
import time
from dataclasses import dataclass, field
from datetime import datetime, timezone
from pathlib import Path

try:
    import requests
except ImportError:
    sys.exit("requests is required: pip3 install requests")

REPO_ROOT = Path(__file__).resolve().parent.parent
LEETCODE_DIR = REPO_ROOT / "leetcode"
SYNC_STATE = LEETCODE_DIR / ".sync-state.json"

GRAPHQL_URL = "https://leetcode.com/graphql/"
BASE_URL = "https://leetcode.com"

# LeetCode throttles hard. Pace requests and back off on 429.
REQUEST_DELAY = 1.1
MAX_RETRIES = 5

LANG_EXT = {
    "cpp": "cpp", "c": "c", "java": "java", "python": "py", "python3": "py",
    "csharp": "cs", "javascript": "js", "typescript": "ts", "php": "php",
    "swift": "swift", "kotlin": "kt", "dart": "dart", "golang": "go",
    "ruby": "rb", "scala": "scala", "rust": "rs", "racket": "rkt",
    "erlang": "erl", "elixir": "ex", "mysql": "sql", "mssql": "sql",
    "oraclesql": "sql", "postgresql": "sql", "pythondata": "py",
    "bash": "sh", "react": "jsx",
}

# Languages whose comment syntax is # rather than //
HASH_COMMENT = {"py", "rb", "sh", "ex", "erl", "rkt", "sql", "ex"}


# --------------------------------------------------------------------------
# credentials
# --------------------------------------------------------------------------

def load_env() -> None:
    """Load .env at repo root into os.environ without overriding real env vars."""
    env_file = REPO_ROOT / ".env"
    if not env_file.exists():
        return
    for line in env_file.read_text().splitlines():
        line = line.strip()
        if not line or line.startswith("#") or "=" not in line:
            continue
        key, _, value = line.partition("=")
        key = key.strip()
        value = value.strip().strip("'\"")
        if key and key not in os.environ:
            os.environ[key] = value


def get_credentials() -> tuple[str, str]:
    load_env()
    session = os.environ.get("LEETCODE_SESSION", "").strip()
    csrf = os.environ.get("LEETCODE_CSRF", "").strip()
    missing = [n for n, v in (("LEETCODE_SESSION", session), ("LEETCODE_CSRF", csrf)) if not v]
    if missing:
        sys.exit(
            f"Missing credential(s): {', '.join(missing)}\n\n"
            "Copy them from your browser (DevTools > Application > Cookies >\n"
            "https://leetcode.com) and put them in a .env file at the repo root:\n\n"
            "    LEETCODE_SESSION=<LEETCODE_SESSION cookie>\n"
            "    LEETCODE_CSRF=<csrftoken cookie>\n\n"
            ".env is gitignored."
        )
    return session, csrf


def session_expiry_note(token: str) -> str:
    """Best-effort read of the JWT payload to warn about expiry. Never fatal."""
    try:
        import base64
        payload_b64 = token.split(".")[1]
        payload_b64 += "=" * (-len(payload_b64) % 4)
        payload = json.loads(base64.urlsafe_b64decode(payload_b64))
        refreshed = payload.get("refreshed_at")
        ttl = payload.get("_session_expiry")
        if refreshed and ttl:
            expires = datetime.fromtimestamp(refreshed + ttl, tz=timezone.utc)
            days = (expires - datetime.now(timezone.utc)).total_seconds() / 86400
            user = payload.get("username", "?")
            if days < 0:
                return f"session for {user} EXPIRED - copy a fresh cookie"
            return f"session for {user}, expires in {days:.1f} days"
    except Exception:
        pass
    return "session token loaded"


# --------------------------------------------------------------------------
# API client
# --------------------------------------------------------------------------

class LeetCode:
    def __init__(self, session_token: str, csrf: str) -> None:
        self.http = requests.Session()
        self.http.cookies.set("LEETCODE_SESSION", session_token, domain=".leetcode.com")
        self.http.cookies.set("csrftoken", csrf, domain=".leetcode.com")
        self.http.headers.update({
            "User-Agent": "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) "
                          "AppleWebKit/537.36 (KHTML, like Gecko) Chrome/122.0 Safari/537.36",
            "Referer": BASE_URL,
            "Origin": BASE_URL,
            "x-csrftoken": csrf,
            "Content-Type": "application/json",
        })
        self.last_request = 0.0

    def _pace(self) -> None:
        elapsed = time.time() - self.last_request
        if elapsed < REQUEST_DELAY:
            time.sleep(REQUEST_DELAY - elapsed)
        self.last_request = time.time()

    def graphql(self, query: str, variables: dict) -> dict:
        for attempt in range(MAX_RETRIES):
            self._pace()
            try:
                resp = self.http.post(
                    GRAPHQL_URL,
                    json={"query": query, "variables": variables},
                    timeout=30,
                )
            except requests.RequestException as exc:
                wait = (2 ** attempt) + random.random()
                print(f"    network error ({exc}); retrying in {wait:.0f}s")
                time.sleep(wait)
                continue

            if resp.status_code == 429:
                wait = (2 ** attempt) * 5 + random.random() * 3
                print(f"    rate limited; backing off {wait:.0f}s")
                time.sleep(wait)
                continue
            if resp.status_code in (401, 403):
                sys.exit(
                    "\nAuthentication rejected (HTTP %d).\n"
                    "The session cookie is probably expired. Copy a fresh\n"
                    "LEETCODE_SESSION and csrftoken from your browser into .env."
                    % resp.status_code
                )
            if resp.status_code >= 500:
                wait = (2 ** attempt) + random.random()
                print(f"    server error {resp.status_code}; retrying in {wait:.0f}s")
                time.sleep(wait)
                continue

            resp.raise_for_status()
            body = resp.json()
            if "errors" in body:
                msg = body["errors"][0].get("message", "unknown GraphQL error")
                raise RuntimeError(f"GraphQL error: {msg}")
            return body.get("data") or {}

        raise RuntimeError("giving up after repeated request failures")

    # -- queries ----------------------------------------------------------

    Q_SUBMISSIONS = """
    query submissionList($offset: Int!, $limit: Int!, $questionSlug: String!) {
      questionSubmissionList(offset: $offset, limit: $limit, questionSlug: $questionSlug) {
        hasNext
        submissions {
          id
          statusDisplay
          lang
          timestamp
          runtime
          memory
        }
      }
    }
    """

    Q_ALL_SUBMISSIONS = """
    query submissions($offset: Int!, $limit: Int!) {
      submissionList(offset: $offset, limit: $limit) {
        hasNext
        submissions {
          id
          title
          titleSlug
          statusDisplay
          lang
          timestamp
          runtime
          memory
        }
      }
    }
    """

    Q_DETAIL = """
    query submissionDetails($submissionId: Int!) {
      submissionDetails(submissionId: $submissionId) {
        code
        lang { name }
        runtimeDisplay
        memoryDisplay
        runtimePercentile
        memoryPercentile
        statusCode
        timestamp
        question { questionId titleSlug title }
      }
    }
    """

    Q_QUESTION = """
    query questionData($titleSlug: String!) {
      question(titleSlug: $titleSlug) {
        questionId
        questionFrontendId
        title
        titleSlug
        difficulty
        topicTags { name }
      }
    }
    """

    def all_submissions_page(self, offset: int, limit: int = 20) -> tuple[list[dict], bool]:
        data = self.graphql(self.Q_ALL_SUBMISSIONS, {"offset": offset, "limit": limit})
        node = data.get("submissionList") or {}
        return node.get("submissions") or [], bool(node.get("hasNext"))

    def problem_submissions_page(self, slug: str, offset: int, limit: int = 20) -> tuple[list[dict], bool]:
        data = self.graphql(self.Q_SUBMISSIONS, {"offset": offset, "limit": limit, "questionSlug": slug})
        node = data.get("questionSubmissionList") or {}
        return node.get("submissions") or [], bool(node.get("hasNext"))

    def submission_detail(self, submission_id: int) -> dict | None:
        data = self.graphql(self.Q_DETAIL, {"submissionId": int(submission_id)})
        return data.get("submissionDetails")

    def question(self, slug: str) -> dict | None:
        data = self.graphql(self.Q_QUESTION, {"titleSlug": slug})
        return data.get("question")


# --------------------------------------------------------------------------
# local storage
# --------------------------------------------------------------------------

def slugify(text: str) -> str:
    return re.sub(r"[^a-z0-9]+", "-", text.lower()).strip("-")


def status_tag(status: str) -> str:
    table = {
        "Accepted": "ac",
        "Wrong Answer": "wa",
        "Time Limit Exceeded": "tle",
        "Memory Limit Exceeded": "mle",
        "Output Limit Exceeded": "ole",
        "Runtime Error": "re",
        "Compile Error": "ce",
    }
    return table.get(status, slugify(status)[:12] or "unknown")


@dataclass
class ProblemIndex:
    """Per-problem sync state, stored at leetcode/<id>/submissions/.index.json"""
    path: Path
    slug: str = ""
    title: str = ""
    difficulty: str = ""
    known_ids: set[str] = field(default_factory=set)
    files: dict[str, str] = field(default_factory=dict)  # submission id -> filename

    @classmethod
    def load(cls, directory: Path) -> "ProblemIndex":
        path = directory / ".index.json"
        idx = cls(path=path)
        if path.exists():
            try:
                raw = json.loads(path.read_text())
            except json.JSONDecodeError:
                print(f"    warning: {path} is corrupt; rebuilding")
                return idx
            idx.slug = raw.get("slug", "")
            idx.title = raw.get("title", "")
            idx.difficulty = raw.get("difficulty", "")
            idx.files = {str(k): v for k, v in (raw.get("files") or {}).items()}
            idx.known_ids = set(idx.files)
        return idx

    def save(self) -> None:
        self.path.parent.mkdir(parents=True, exist_ok=True)
        payload = {
            "slug": self.slug,
            "title": self.title,
            "difficulty": self.difficulty,
            "synced_at": datetime.now(timezone.utc).isoformat(timespec="seconds"),
            "files": dict(sorted(self.files.items(), key=lambda kv: int(kv[0]))),
        }
        self.path.write_text(json.dumps(payload, indent=2) + "\n")

    def has(self, submission_id: str, directory: Path) -> bool:
        """Known AND the file still exists - deleting a file re-fetches it."""
        name = self.files.get(str(submission_id))
        return bool(name) and (directory / name).exists()


def load_sync_state() -> dict:
    if SYNC_STATE.exists():
        try:
            return json.loads(SYNC_STATE.read_text())
        except json.JSONDecodeError:
            pass
    return {}


def save_sync_state(state: dict) -> None:
    SYNC_STATE.parent.mkdir(parents=True, exist_ok=True)
    SYNC_STATE.write_text(json.dumps(state, indent=2) + "\n")


def header_for(detail: dict, meta: dict, submission_id: str, status: str, ext: str) -> str:
    when = datetime.fromtimestamp(int(detail.get("timestamp") or 0), tz=timezone.utc)
    lines = [
        f"{meta.get('frontend_id', '?')}. {meta.get('title', '')}".strip(),
        f"Difficulty: {meta.get('difficulty', 'Unknown')}",
        f"Status: {status}",
    ]
    runtime = detail.get("runtimeDisplay")
    memory = detail.get("memoryDisplay")
    rt_pct = detail.get("runtimePercentile")
    mem_pct = detail.get("memoryPercentile")
    if runtime:
        lines.append(f"Runtime: {runtime}" + (f" (beats {rt_pct:.1f}%)" if rt_pct else ""))
    if memory:
        lines.append(f"Memory: {memory}" + (f" (beats {mem_pct:.1f}%)" if mem_pct else ""))
    lines.append(f"Submitted: {when.strftime('%Y-%m-%d %H:%M:%S UTC')}")
    lines.append(f"URL: {BASE_URL}/submissions/detail/{submission_id}/")

    if ext in HASH_COMMENT:
        return "\n".join(f"# {ln}" for ln in lines) + "\n\n"
    body = "\n".join(f" * {ln}" for ln in lines)
    return f"/*\n{body}\n */\n\n"


# --------------------------------------------------------------------------
# sync
# --------------------------------------------------------------------------

class Stats:
    def __init__(self) -> None:
        self.downloaded = 0
        self.skipped = 0
        self.problems = 0
        self.errors = 0


def sync_problem(api: LeetCode, slug: str, args, stats: Stats,
                 question_meta: dict | None = None) -> None:
    """Download submissions for one problem, stopping at the first known one."""
    meta = question_meta or api.question(slug)
    if not meta:
        print(f"  ! could not resolve problem '{slug}'")
        stats.errors += 1
        return

    frontend_id = str(meta.get("questionFrontendId") or meta.get("questionId"))
    title = meta.get("title", slug)
    difficulty = meta.get("difficulty", "")

    problem_dir = LEETCODE_DIR / frontend_id
    sub_dir = problem_dir / "submissions"
    index = ProblemIndex.load(sub_dir)
    index.slug, index.title, index.difficulty = slug, title, difficulty

    meta_info = {"frontend_id": frontend_id, "title": title, "difficulty": difficulty}

    print(f"\n[{frontend_id}] {title} ({difficulty})")
    stats.problems += 1

    # A file can be missing while its id is still indexed (deleted by hand, or a
    # failed write). Early-stop walks newest-first and would break before ever
    # reaching an older gap, so disable it whenever the index has one.
    missing = [sid for sid in index.files if not index.has(sid, sub_dir)]
    if missing:
        print(f"  {len(missing)} indexed file(s) missing; scanning full history to restore")

    allow_early_stop = not args.full and not missing

    offset = 0
    new_here = 0
    stop = False

    while not stop:
        try:
            page, has_next = api.problem_submissions_page(slug, offset)
        except RuntimeError as exc:
            print(f"  ! {exc}")
            stats.errors += 1
            break
        if not page:
            break

        for sub in page:
            sid = str(sub["id"])
            status = sub.get("statusDisplay") or "Unknown"

            known = sid in index.known_ids or sid in index.files
            on_disk = index.has(sid, sub_dir)

            if on_disk:
                # Newest-first ordering: everything past this is already local,
                # but only when no earlier submission is missing its file.
                if allow_early_stop:
                    stop = True
                    break
                stats.skipped += 1
                continue

            if known:
                # Indexed but the file is gone (deleted, or a failed write).
                # Re-fetch it and keep scanning rather than stopping here.
                print(f"  ~ {index.files.get(sid, sid)} missing; restoring")

            if status != "Accepted" and not args.include_failed:
                stats.skipped += 1
                continue

            lang = (sub.get("lang") or "").lower()
            ext = LANG_EXT.get(lang, "txt")
            ts = datetime.fromtimestamp(int(sub.get("timestamp") or 0), tz=timezone.utc)
            filename = f"{ts.strftime('%Y%m%d-%H%M%S')}-{status_tag(status)}-{lang or 'unknown'}.{ext}"
            target = sub_dir / filename

            if args.dry_run:
                print(f"  + would download {filename}")
                stats.downloaded += 1
                new_here += 1
                index.files[sid] = filename
                continue

            try:
                detail = api.submission_detail(int(sid))
            except RuntimeError as exc:
                print(f"  ! submission {sid}: {exc}")
                stats.errors += 1
                continue

            if not detail or not detail.get("code"):
                print(f"  ! submission {sid}: no source returned")
                stats.errors += 1
                continue

            sub_dir.mkdir(parents=True, exist_ok=True)
            code = detail["code"]
            if not code.endswith("\n"):
                code += "\n"
            target.write_text(header_for(detail, meta_info, sid, status, ext) + code)
            index.files[sid] = filename
            stats.downloaded += 1
            new_here += 1
            print(f"  + {filename}")

        if stop or not has_next:
            break
        offset += len(page)

    if new_here and not args.dry_run:
        index.save()
    elif new_here:
        print(f"  ({new_here} new, dry run - nothing written)")

    if not new_here:
        print("  up to date")


def discover_slugs(api: LeetCode, args, state: dict) -> list[tuple[str, dict | None]]:
    """Walk the global submission feed to find problems with submissions.

    Incremental mode stops at the newest submission id seen on the last run.
    """
    last_seen = state.get("newest_submission_id")
    seen: dict[str, None] = {}
    newest: str | None = None
    offset = 0

    print("Scanning submission history...")
    while True:
        try:
            page, has_next = api.all_submissions_page(offset)
        except RuntimeError as exc:
            print(f"  ! {exc}")
            break
        if not page:
            break

        for sub in page:
            sid = str(sub["id"])
            if newest is None:
                newest = sid
            if last_seen and sid == last_seen and not args.full:
                print(f"  reached last synced submission ({sid})")
                if newest:
                    state["newest_submission_id"] = newest
                return [(s, None) for s in seen]
            slug = sub.get("titleSlug")
            if slug and slug not in seen:
                seen[slug] = None

        offset += len(page)
        print(f"  ...{offset} submissions scanned, {len(seen)} problems")
        if not has_next:
            break

    if newest:
        state["newest_submission_id"] = newest
    return [(s, None) for s in seen]


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Download LeetCode submissions into this repo.",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog=__doc__,
    )
    parser.add_argument("--problem", action="append", default=[],
                        help="problem slug or frontend id (repeatable)")
    parser.add_argument("--full", action="store_true",
                        help="rescan everything instead of stopping at known submissions")
    parser.add_argument("--include-failed", action="store_true",
                        help="also download non-accepted submissions")
    parser.add_argument("--dry-run", action="store_true",
                        help="report what would be downloaded, write nothing")
    args = parser.parse_args()

    session_token, csrf = get_credentials()
    print(session_expiry_note(session_token))

    api = LeetCode(session_token, csrf)
    state = load_sync_state()
    stats = Stats()

    if args.problem:
        targets: list[tuple[str, dict | None]] = []
        for raw in args.problem:
            raw = raw.strip()
            if raw.isdigit():
                idx_path = LEETCODE_DIR / raw / "submissions" / ".index.json"
                if idx_path.exists():
                    slug = json.loads(idx_path.read_text()).get("slug")
                    if slug:
                        targets.append((slug, None))
                        continue
                print(f"! problem {raw} has no known slug; pass the slug instead "
                      f"(e.g. --problem two-sum)")
                stats.errors += 1
            else:
                targets.append((raw, None))
    else:
        targets = discover_slugs(api, args, state)

    if not targets:
        print("\nNothing to sync.")
        return 0

    print(f"\n{len(targets)} problem(s) to check")
    for slug, meta in targets:
        try:
            sync_problem(api, slug, args, stats, meta)
        except KeyboardInterrupt:
            print("\nInterrupted - progress so far is saved.")
            break
        except Exception as exc:  # keep going; one bad problem shouldn't stop the run
            print(f"  ! unexpected error on {slug}: {exc}")
            stats.errors += 1

    if not args.dry_run:
        state["synced_at"] = datetime.now(timezone.utc).isoformat(timespec="seconds")
        save_sync_state(state)

    print("\n" + "=" * 50)
    print(f"problems checked : {stats.problems}")
    print(f"downloaded       : {stats.downloaded}")
    print(f"skipped          : {stats.skipped}")
    print(f"errors           : {stats.errors}")
    if args.dry_run:
        print("\n(dry run - no files written)")
    return 1 if stats.errors and not stats.downloaded else 0


if __name__ == "__main__":
    sys.exit(main())
