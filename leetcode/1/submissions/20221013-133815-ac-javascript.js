/*
 * 1. Two Sum
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 67 ms (beats 10.3%)
 * Memory: 43.5 MB (beats 100.0%)
 * Submitted: 2022-10-13 13:38:15 UTC
 * URL: https://leetcode.com/submissions/detail/821636492/
 */

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let map = new Map();
    for(let i = 0; i < nums.length; i++){
        if(map.has(nums[i])){
            return [i, map.get(nums[i])];
        }else{
            map.set(target - nums[i], i);
        }
    }
    return false;
};
