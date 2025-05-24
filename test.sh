# test.sh
#!/bin/bash

# Check if a problem directory was passed as argument
if [ "$1" ]; then
    SOLUTION_DIR="$1"
    echo "🔍 Using specified directory: $SOLUTION_DIR"
else
    # Fallback: Find the directory containing solution.cpp
    if [ -f "solution.cpp" ]; then
        SOLUTION_DIR="."
    else
        SOLUTION_DIR=$(find problems -name "solution.cpp" -type f | head -1 | xargs dirname 2>/dev/null)
        if [ -z "$SOLUTION_DIR" ]; then
            echo "❌ solution.cpp not found. Please specify problem directory as argument."
            echo "Usage: $0 [problem_directory]"
            exit 1
        fi
        echo "🔍 Found solution.cpp in: $SOLUTION_DIR"
    fi
fi

# Check if the directory exists and contains solution.cpp
if [ ! -d "$SOLUTION_DIR" ]; then
    echo "❌ Directory $SOLUTION_DIR does not exist"
    exit 1
fi

if [ ! -f "$SOLUTION_DIR/solution.cpp" ]; then
    echo "❌ solution.cpp not found in $SOLUTION_DIR"
    exit 1
fi

cd "$SOLUTION_DIR"

# Compile first
echo "🔧 Compiling..."
g++ -DLOCAL -std=c++17 -O2 -Wall -Wextra -o solution solution.cpp
if [ $? -ne 0 ]; then
    echo "❌ Compilation failed"
    exit 1
fi
echo "✅ Compilation successful"

# Run the solution
echo "🔄 Running solution..."
./solution

# Compare output if expected output exists
if [ -f "expected_output.txt" ]; then
    echo "📊 Comparing outputs..."
    if diff -w output.txt expected_output.txt > /dev/null; then
        echo "✅ Output matches expected result!"
    else
        echo "❌ Output differs from expected result:"
        echo "--- Expected ---"
        cat expected_output.txt
        echo "--- Got ---"
        cat output.txt
        echo "--- Diff ---"
        diff -w expected_output.txt output.txt
    fi
else
    echo "📄 Output:"
    cat output.txt
fi

# Show debug info if available
if [ -s "error.txt" ]; then
    echo "🐛 Debug info:"
    cat error.txt
fi
