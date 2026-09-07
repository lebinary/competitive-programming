/*
 * 22. Generate Parentheses
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 112 ms (beats 5.4%)
 * Memory: 42.8 MB (beats 100.0%)
 * Submitted: 2022-11-07 15:10:45 UTC
 * URL: https://leetcode.com/submissions/detail/838756595/
 */

/**
 * @param {number} n
 * @return {string[]}
 */

 /**
 RULES:
 - Only add close parentheses when closeN < openN
 - Only add open parentheses when openN < n
 - A valid parentheses when n = openN = closeN
  */
var generateParenthesis = function(n) {
    const res = [];
    const stack = [];

    const backTrack = (openN, closeN) => {
        if(openN === n && closeN === n){
            res.push(stack.join(""));
            return;
        }

        if(closeN < openN){
            stack.push(")");
            backTrack(openN, closeN + 1);
            stack.pop();
        }

        if(openN < n){
            stack.push("(");
            backTrack(openN + 1, closeN);
            stack.pop();
        }
    }

    backTrack(0, 0);

    return res;
};
