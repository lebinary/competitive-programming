/*
 * 20. Valid Parentheses
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 116 ms (beats 5.0%)
 * Memory: 42.5 MB (beats 100.0%)
 * Submitted: 2022-08-06 04:27:12 UTC
 * URL: https://leetcode.com/submissions/detail/766362163/
 */

/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    const stack = [];
    
    for(let i = 0; i < s.length; i++){
        if(s[i] === "(" || s[i] === "{" || s[i] === "[" ){
            stack.push(s[i]);
        }
        
        else if(s[i] === ")"){
            if(stack.pop() !== "("){
                return false;
            }
        }
        
        else if(s[i] === "}"){
            if(stack.pop() !== "{"){
                return false;
            }
        }
        
        else if(s[i] === "]"){
            if(stack.pop() !== "["){
                return false;
            }
        }
    }
    
    if(stack.length > 0){
        return false
    }
    
    return true;
};
