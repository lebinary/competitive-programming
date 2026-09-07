# LeetCode submission sync

Downloads your LeetCode submissions into `leetcode/<id>/submissions/`.
Re-running it only fetches what is new, so it is cheap to run often.

## Setup

LeetCode has no public API for submissions, so the script authenticates with
your own browser cookies.
There is no token or OAuth alternative.

Open <https://leetcode.com> while logged in, then DevTools > Application >
Cookies > `https://leetcode.com`, and copy two values:

- `LEETCODE_SESSION` - a long JWT
- `csrftoken` - a shorter alphanumeric string

Put them in a `.env` file at the repo root:

```
LEETCODE_SESSION=<LEETCODE_SESSION cookie>
LEETCODE_CSRF=<csrftoken cookie>
```

`.env` is gitignored, so the credentials never enter version control.
Real environment variables take precedence over `.env` if both are set.

The session cookie expires after about two weeks.
When it does, the script exits with an authentication error and you paste a
fresh cookie.
On startup it prints how many days the current token has left.

## Usage

```bash
# Incremental: only submissions newer than the last run. This is the normal one.
python3 scripts/leetcode_sync.py

# See what would happen without writing anything.
python3 scripts/leetcode_sync.py --dry-run

# Re-check every problem from scratch. Still skips files already on disk.
python3 scripts/leetcode_sync.py --full

# One problem, by slug or by frontend id (id works once it has been synced once).
python3 scripts/leetcode_sync.py --problem two-sum
python3 scripts/leetcode_sync.py --problem 84

# Include wrong-answer, TLE, runtime-error attempts as well as accepted ones.
python3 scripts/leetcode_sync.py --include-failed
```

Start with `--dry-run` on the first run to confirm the credentials work and to
see how many submissions are involved before committing to a long download.

## Layout

```
leetcode/84/
  problem.md                       # yours, never touched
  opt_divide_conquer.cpp           # yours, never touched
  submissions/
    .index.json                    # sync state for this problem
    20240115-143022-ac-cpp.cpp     # <date>-<time>-<status>-<lang>
    20240118-091133-wa-cpp.cpp
```

Downloaded code always goes in `submissions/`, never in the problem root, so it
cannot overwrite anything you wrote by hand.
Each file gets a header comment with status, runtime, memory, and a link back to
the submission.

Status tags in filenames: `ac`, `wa`, `tle`, `mle`, `ole`, `re`, `ce`.

## How incremental sync works

Two pieces of state drive it:

- `leetcode/.sync-state.json` holds the newest submission id seen across the
  whole account.
  A normal run walks your submission feed and stops as soon as it reaches that
  id, so it does not page through years of history every time.
- `leetcode/<id>/submissions/.index.json` maps submission id to filename for one
  problem.
  When scanning a problem, the script stops at the first submission already in
  that index, since the feed is ordered newest first.

Because both files are committed, the sync state travels with the repo.

Files already on disk are never re-fetched or overwritten.
Deleting a downloaded file and re-running restores it, which is the supported
way to repair a bad download.
A corrupt `.index.json` is detected and rebuilt rather than crashing the run.

## Rate limiting

LeetCode throttles aggressively.
Requests are paced about one per second with exponential backoff on HTTP 429 and
5xx.
A first full sync of a large history takes a while but runs unattended.
Interrupting with Ctrl-C is safe: everything downloaded so far is already
written and indexed.
