/*
 * 739. Daily Temperatures
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 527 ms (beats 5.1%)
 * Memory: 73.1 MB (beats 99.9%)
 * Submitted: 2022-11-08 13:44:47 UTC
 * URL: https://leetcode.com/submissions/detail/839434418/
 */

/**
 * @param {number[]} temperatures
 * @return {number[]}
 */

/***
stack = []
temp  = [73, 74, 75, 71, 69, 72, 76, 73]
 */

var dailyTemperatures = function(temperatures) {
    const stack = [];

    for(let i = 0; i < temperatures.length; i++){
        while(stack.length > 0 && temperatures[i] > stack[stack.length - 1][1]){
            let pop = stack.pop();
            let popIndex = pop[0];
            temperatures[popIndex] = i - popIndex;
        }

        stack.push([i, temperatures[i]]);
        temperatures[i] = 0;
    }
    return temperatures;
};
