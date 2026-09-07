/*
 * 32. Longest Valid Parentheses
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 11.8 MB (beats 50.0%)
 * Submitted: 2026-04-02 09:12:01 UTC
 * URL: https://leetcode.com/submissions/detail/1966650637/
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), res = 0;

        stack<int> invalid;
        invalid.push(-1);

        for(int i = 0; i < n; ++i) {
            if(s[i] == '(') invalid.push(i);
            else {
                // clear out the valid
                if(invalid.size() > 1 && s[invalid.top()] == '(') {
                    invalid.pop();
                    if((i - invalid.top()) % 2 == 0) res = max(res, i - invalid.top());
                } else {
                    invalid.push(i);
                }
            }
        }

        return res;
    }
};

/**
Approach: top of the stack will store "the leftmost invalid parentheses"
- if see "(": push onto the stack
- if see ")": there are 2 cases:
    valid ")": pop out the corresponding "valid" parentheses, update result
    invalid ")": push onto the start, start the new cycle
**/
