/*
 * 150. Evaluate Reverse Polish Notation
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 144 ms (beats 7.3%)
 * Memory: 44.6 MB (beats 100.0%)
 * Submitted: 2022-11-07 14:34:50 UTC
 * URL: https://leetcode.com/submissions/detail/838736543/
 */

/**
 * @param {string[]} tokens
 * @return {number}
 */
var evalRPN = function(tokens) {
    let stack = [];

    for(let i = 0; i < tokens.length; i++){
        if(tokens[i] === "+"){
            const r = stack.pop();
            const l = stack.pop();
            stack.push(l + r);
        }
        else if(tokens[i] === "*"){
            const r = stack.pop();
            const l = stack.pop();
            stack.push(l * r);
        }
        else if(tokens[i] === "-"){
            const r = stack.pop();
            const l = stack.pop();
            stack.push(l - r);
        }
        else if(tokens[i] === "/"){
            const r = stack.pop();
            const l = stack.pop();
            stack.push(Math.trunc(l / r));
        }else {
            stack.push(parseInt(tokens[i]));
        }
    }

    return stack.pop();
};
