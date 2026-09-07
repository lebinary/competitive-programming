/*
 * 227. Basic Calculator II
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 3 ms (beats 89.6%)
 * Memory: 11.8 MB (beats 98.4%)
 * Submitted: 2026-03-12 18:14:05 UTC
 * URL: https://leetcode.com/submissions/detail/1946340022/
 */

class Solution {
public:
    int calculate(string s) {
        int n = s.size(), res = 0;

        int currNum = 0, lastNum = 0;
        char op = '+';

        for(int i = 0; i < n; ++i) {
            if(isdigit(s[i])) currNum = currNum * 10 + (s[i] - '0');
            
            bool isOp = !isdigit(s[i]) && !iswspace(s[i]);
            if(isOp || i == n - 1) {
                if(op == '+') {
                    res += lastNum;
                    lastNum = currNum;
                }
                else if(op == '-') {
                    res += lastNum;
                    lastNum = -currNum;
                }
                else if(op == '*') lastNum *= currNum;
                else lastNum /= currNum;

                currNum = 0;
                op = s[i];
            }
        }

        res += lastNum;

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

# Approach2: 2 scans, one for "* /" and one for "+-"
- Scan
**/
