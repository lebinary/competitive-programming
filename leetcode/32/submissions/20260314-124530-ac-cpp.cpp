/*
 * 32. Longest Valid Parentheses
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 6 ms (beats 11.2%)
 * Memory: 11.6 MB (beats 83.8%)
 * Submitted: 2026-03-14 12:45:31 UTC
 * URL: https://leetcode.com/submissions/detail/1947898195/
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), res = 0;
        stack<int> stack;

        stack.push(-1);
        for(int i = 0; i < n; ++i) {
            if(s[i] == '(') stack.push(i);
            else {
                int top = stack.top();
                stack.pop();

                if(top > - 1 && s[top] == '(') {
                    res = max(res, i - stack.top());
                } else {
                    stack.push(i);
                }
            }
        }

        return res;
    }
};

/**
# Approach 2: stack
- Stack can be use to validate valid parentheses
- In this problem, its not clear when to start validating, i.e:
    ") ( ) ( ) )"
    "F T T T T F"

    => if we can identify the "F" right before the valid string, then we solved the problem

    => SOL: use stack to store " The latest invalid "F",
        Need to maintain this: at all point, top of stack can only have either:
            - index of a "("
            - the lastest invalid "F"
        So that, when encounter a ")", 2 scenarios on top of the stack:
            - index of a "(": pop, check result
            - the latest invalid "F": pop, dont check result, i now the new invalid "F"

- Let i be current postion index: 
    if s[i] = ')' and s[stack.top] = '(': 
        stack.pop
        res = max(res, i - stacktop)
        
    if s[i] = '(':
        stack << i 

- Edge case:
    s[i] = ')' and stack.empty:
        stack << i
**/
