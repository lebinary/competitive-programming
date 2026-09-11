#!/bin/bash
# Compile and run a solution, or build a single-file submission.
#
#   ./run.sh <problem_dir>            compile + run against input.txt
#   ./run.sh <problem_dir> submit     write submit.cpp with cp.h inlined
#
# Works for any judge that takes a single pasted file (CSES, Codeforces, ...).
# solution.cpp only contains solve(); everything else lives in cp.h.
#
# Uses g++-15: the default `g++` here is Apple clang, which has no
# <bits/stdc++.h>. Install with: brew install gcc

set -euo pipefail

if [ "$#" -lt 1 ]; then
    echo "Usage: $0 <problem_dir> [submit]"
    exit 1
fi

DIR="${1%/}"
MODE="${2:-run}"
CXX="${CXX:-g++-15}"
HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

if [ ! -f "$DIR/solution.cpp" ]; then
    echo "solution.cpp not found in $DIR"
    exit 1
fi

if [ "$MODE" = "submit" ]; then
    # Replace the #include "cp.h" line with the header's contents.
    awk -v hdr="$HERE/cp.h" '
        /^[[:space:]]*#include[[:space:]]*"(\.\.\/)*cp\.h"[[:space:]]*$/ {
            while ((getline line < hdr) > 0) print line
            next
        }
        { print }
    ' "$DIR/solution.cpp" > "$DIR/submit.cpp"
    echo "wrote $DIR/submit.cpp - paste this into the judge"
    # Sanity-check that the stitched file actually builds.
    "$CXX" -std=c++17 -O2 -o /dev/null "$DIR/submit.cpp"
    echo "submit.cpp compiles clean"
    exit 0
fi

"$CXX" -DLOCAL -std=c++17 -O2 -Wall -Wextra -I"$HERE" -o "$DIR/solution" "$DIR/solution.cpp"
( cd "$DIR" && ./solution )
rm -f "$DIR/solution"
