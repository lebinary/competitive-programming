/*
 * 167. Two Sum II - Input Array Is Sorted
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 78 ms (beats 7.3%)
 * Memory: 43.4 MB (beats 100.0%)
 * Submitted: 2022-05-25 13:53:19 UTC
 * URL: https://leetcode.com/submissions/detail/706941929/
 */

/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(numbers, target) {
    let l = 0;
    let r = numbers.length - 1;
    
    while(l < r){
        const sum = numbers[l] + numbers[r]; 
        if(sum === target) return [l+1, r+1];
        else if(sum > target) r--;
        else l++;
    }
};
