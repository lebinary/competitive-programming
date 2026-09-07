/*
 * 33. Search in Rotated Sorted Array
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 53 ms (beats 4.6%)
 * Memory: 41.7 MB (beats 100.0%)
 * Submitted: 2022-11-24 14:58:18 UTC
 * URL: https://leetcode.com/submissions/detail/849163856/
 */

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    // Find pivot
    let l = 0;
    let r = nums.length - 1;

    while(l <= r){
        let mid = Math.floor((l + r) / 2);

        if(nums[mid] === target){
            return mid;
        }

        // Left portion
        if(nums[l] <= nums[mid]){
            if(target < nums[l] || target > nums[mid]){
                l = mid + 1;
            }else {
                r = mid - 1;
            }
        }

        // Right portion
        else{
            if(target > nums[r] || target < nums[mid]){
                r = mid - 1;
            }else {
                l = mid + 1;
            }
        }
    }

    return -1;
};
