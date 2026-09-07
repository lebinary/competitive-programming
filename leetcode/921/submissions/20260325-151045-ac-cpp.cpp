/*
 * 921. Minimum Add to Make Parentheses Valid
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 8.5 MB (beats 57.1%)
 * Submitted: 2026-03-25 15:10:45 UTC
 * URL: https://leetcode.com/submissions/detail/1958979355/
 */

class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int openCount = 0, closeCount = 0;

        for(int i = 0; i < n; ++i) {
            if(s[i] == '(') openCount++;
            else {
                if(openCount > 0) openCount--;
                else closeCount++;
            }
        }

        return openCount + closeCount;
    }
};

/**
s = "())(" res=2
s = "(()(" res=2
res = stack.size() + "orphan closing parenthesis"
stack.size() == "orphan operning parenthesis"

# Approach:  
- for each parenthesis:
    openParenthesis++ if curr is open parenthesis
    closedParenthesis++ if curr is close parenthesis and openParethesis == 0
    openParenthesis-- if curr is close and openParenthesis > 0
- return openParenthesis + closedParenthesis
**/
