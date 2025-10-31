#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Usage: ./run.sh <path_to_problem>"
    echo "Example: ./run.sh leetcode/90"
    exit 1
fi

PROBLEM_PATH=$1

if [ ! -d "$PROBLEM_PATH" ]; then
    echo "Error: Directory $PROBLEM_PATH does not exist"
    exit 1
fi

if [ ! -f "$PROBLEM_PATH/run.cpp" ]; then
    echo "Error: $PROBLEM_PATH/run.cpp does not exist"
    exit 1
fi

echo "Compiling $PROBLEM_PATH/run.cpp..."
g++ -std=c++17 "$PROBLEM_PATH/run.cpp" -o "$PROBLEM_PATH/run"

if [ $? -ne 0 ]; then
    echo "Compilation failed"
    exit 1
fi

echo "Running tests..."
echo "---"
"$PROBLEM_PATH/run"

rm "$PROBLEM_PATH/run"
