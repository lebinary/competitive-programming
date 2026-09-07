/*
 * 739. Daily Temperatures
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 313 ms (beats 5.1%)
 * Memory: 69.2 MB (beats 100.0%)
 * Submitted: 2022-08-08 14:33:56 UTC
 * URL: https://leetcode.com/submissions/detail/768469980/
 */

/**
 * @param {number[]} temperatures
 * @return {number[]}
 */
var dailyTemperatures = function(temperatures) {
    const stack = [];
    
    for(let i = 0; i < temperatures.length; i++){
        while(stack.length > 0 && temperatures[i] > stack[stack.length -1 ][1]){
            const stackPop = stack.pop();
            const prevIndex = stackPop[0];
            temperatures[prevIndex] = i - prevIndex;
        }
        
        stack.push([i, temperatures[i]]);
        temperatures[i] = 0;
    }
    
    return temperatures;
};
