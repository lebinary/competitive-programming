/*
 * 167. Two Sum II - Input Array Is Sorted
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 75 ms (beats 7.3%)
 * Memory: 42.7 MB (beats 100.0%)
 * Submitted: 2022-10-26 15:19:37 UTC
 * URL: https://leetcode.com/submissions/detail/830775437/
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
        if(numbers[l] + numbers[r] === target) return [l+1, r+1];
        else if(numbers[l] + numbers[r] > target) r--;
        else l++;
    }
};
