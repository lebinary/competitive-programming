/*
 * 20. Valid Parentheses
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 103 ms (beats 5.0%)
 * Memory: 42.8 MB (beats 100.0%)
 * Submitted: 2022-11-04 14:14:50 UTC
 * URL: https://leetcode.com/submissions/detail/836773555/
 */

/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let stack = [];
    for(let i = 0; i < s.length; i++){
        if(s[i] === "(" || s[i] === "[" || s[i] === "{"){
            stack.push(s[i]);
        }
        else if(s[i] === ")"){                
            if(stack.pop() !== "("){
                return false;
            }
        }
        else if(s[i] === "]"){
            if(stack.pop() !== "["){
                return false;
            }
        }else if(s[i] === "}"){
            if(stack.pop() !== "{"){
                return false;
            }
        }
    }

    if(stack.length !== 0) return false;

    return true;
};
