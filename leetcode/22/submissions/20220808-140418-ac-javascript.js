/*
 * 22. Generate Parentheses
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 105 ms (beats 5.4%)
 * Memory: 42.7 MB (beats 100.0%)
 * Submitted: 2022-08-08 14:04:18 UTC
 * URL: https://leetcode.com/submissions/detail/768447648/
 */

/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    // Only add open if open < n
    // Only add close if close < open
    // Valid if open == close == n
    
    const stack = [];
    const res = [];
    
    let backtrack = (openN, closeN) => {
        if(openN === n &&  closeN === n){
            res.push(stack.join(""))
            return;
        }
        
        if(openN < n){
            stack.push("(");
            backtrack(openN + 1, closeN);
            stack.pop();
        }
        
        if(closeN < openN){
            stack.push(")");
            backtrack(openN, closeN + 1);
            stack.pop();
        }
    }
    
    backtrack(0, 0);
    
    return res;
};
