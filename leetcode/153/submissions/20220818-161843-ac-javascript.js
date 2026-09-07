/*
 * 153. Find Minimum in Rotated Sorted Array
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 102 ms (beats 3.0%)
 * Memory: 42.1 MB (beats 100.0%)
 * Submitted: 2022-08-18 16:18:43 UTC
 * URL: https://leetcode.com/submissions/detail/777048622/
 */

/**
 * @param {number[]} nums
 * @return {number}
 */
var findMin = function(nums) {
    let l = 0;
    let r = nums.length - 1;
    let res = nums[0];
    
    while(l <= r){        
        if(nums[l] < nums[r]){
            res = Math.min(res, nums[l]);
            break;
        }
        
        let mid = Math.floor((l + r) / 2);
        res = Math.min(res, nums[mid]);
        
        // Check if we in left portion
        if(nums[mid] >= nums[l]){
            l = mid + 1;
        }
        
        // In right portion
        else{
            r = mid - 1;
        }
    }
    
    return res;
};
