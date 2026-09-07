/*
 * 33. Search in Rotated Sorted Array
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 101 ms (beats 4.6%)
 * Memory: 42.4 MB (beats 100.0%)
 * Submitted: 2022-08-17 14:59:11 UTC
 * URL: https://leetcode.com/submissions/detail/776118669/
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
        let mid = Math.floor((l+r) / 2);
        
        if(nums[mid] === target){
            return mid;
        }
        
        // Left sorted portion
        if(nums[l] <= nums[mid]){
            if(target < nums[l] || target > nums[mid]){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        
        // Right sorted portion
        else{
            if(target > nums[r] || target < nums[mid]){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
    }
    
    return -1;
};
