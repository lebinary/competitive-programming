/*
 * 153. Find Minimum in Rotated Sorted Array
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 64 ms (beats 3.0%)
 * Memory: 38.9 MB (beats 100.0%)
 * Submitted: 2021-11-17 13:46:58 UTC
 * URL: https://leetcode.com/submissions/detail/588588495/
 */

/**
 * @param {number[]} nums
 * @return {number}
 */
var findMin = function(nums) {
    let time_rotated = 0;
    for(let i = 1; i < nums.length; i++){
        time_rotated++;
        if(nums[i] < nums[i-1]) {
            return nums[i];
        }
    }
    return nums[0];
};
