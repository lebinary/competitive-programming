/*
 * 704. Binary Search
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 113 ms (beats 1.9%)
 * Memory: 44.8 MB (beats 100.0%)
 * Submitted: 2022-11-15 14:02:40 UTC
 * URL: https://leetcode.com/submissions/detail/843922898/
 */

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    let l = 0;
    let r = nums.length - 1;

    while(l <= r){
        const pivot = Math.floor((r + l) / 2);
        if(nums[pivot] === target) return pivot;
        if(nums[pivot] < target){
            l = pivot + 1;
        }
        else if(nums[pivot] > target){
            r = pivot - 1;
        }
    }

    return -1;
};
