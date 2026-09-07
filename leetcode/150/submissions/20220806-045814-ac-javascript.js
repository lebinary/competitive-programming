/*
 * 150. Evaluate Reverse Polish Notation
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 82 ms (beats 9.4%)
 * Memory: 44.2 MB (beats 100.0%)
 * Submitted: 2022-08-06 04:58:14 UTC
 * URL: https://leetcode.com/submissions/detail/766377145/
 */

/**
 * @param {string[]} tokens
 * @return {number}
 */
var evalRPN = function(tokens) {
    const stack = [];
    
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
