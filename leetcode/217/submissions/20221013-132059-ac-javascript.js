/*
 * 217. Contains Duplicate
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 137 ms (beats 5.1%)
 * Memory: 50.1 MB (beats 100.0%)
 * Submitted: 2022-10-13 13:20:59 UTC
 * URL: https://leetcode.com/submissions/detail/821626873/
 */

/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    let set = new Set();
    for(let i = 0; i < nums.length; i++){
        if(set.has(nums[i])){
            return true;
        }else{
            set.add(nums[i]);
        }
    }
    return false;
};
