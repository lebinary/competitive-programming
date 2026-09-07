/*
 * 32. Longest Valid Parentheses
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 11.9 MB (beats 22.5%)
 * Submitted: 2026-04-02 09:10:23 UTC
 * URL: https://leetcode.com/submissions/detail/1966649362/
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
- if see ")": pop out all the "valid" parentheses, whats left is the invalid
    => update res = current index - last invalid
**/






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
