/*
 * 227. Basic Calculator II
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 7 ms (beats 63.0%)
 * Memory: 15 MB (beats 76.7%)
 * Submitted: 2026-03-12 17:35:40 UTC
 * URL: https://leetcode.com/submissions/detail/1946295969/
 */

class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        vector<int> stack;

        int currNum = 0;
        char op = '+';
        for(int i = 0; i < n; ++i) {
            if(isdigit(s[i])) currNum = currNum * 10 + (s[i] - '0');
            
            bool isOp = !isdigit(s[i]) && !iswspace(s[i]);
            if(isOp || i == n - 1) {
                if(op == '+') stack.push_back(currNum);
                else if(op == '-') stack.push_back(-currNum);
                else {
                    int top = stack.back();
                    stack.pop_back();

                    if(op == '*') stack.push_back(top * currNum);
                    else stack.push_back(top / currNum); 
                }

                currNum = 0;
                op = s[i];
            }
        }

        int res = 0;
        while(!stack.empty()) {
            res += stack.back();
            stack.pop_back();
        }

        return res;
    }
};


/**
Example: "3 + 2 * 2 + 3 / 3"

stack = [3,4,1]
ops = [+,+]


Example: "3 + 2 * 2 / 4 + 3"
stack = [3, 2, 2, 4, 3]
ops =   [+, *, /, +]

Example: "10 + 3 * 20"


# Approach1: Stack + 2 scans
- Scan first time: only process the * and / operations
- Scan second time: get the final result

# Approach2: 
**/
