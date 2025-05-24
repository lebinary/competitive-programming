# submit.sh (removes local testing code)
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

echo "🚀 Preparing submission..."
# Remove LOCAL-specific code for submission
sed '/#ifdef LOCAL/,/#endif/d' solution.cpp > submission.cpp
echo "✅ Clean submission code created as submission.cpp"
echo "📋 Code is ready to copy-paste for submission"
