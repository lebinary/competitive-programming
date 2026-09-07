/*
 * 152. Maximum Product Subarray
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 112 ms (beats 8.4%)
 * Memory: 43.6 MB (beats 100.0%)
 * Submitted: 2021-11-10 14:40:37 UTC
 * URL: https://leetcode.com/submissions/detail/585039936/
 */

/**
 * @param {number[]} nums
 * @return {number}
 */
var maxProduct = function(nums) {
    if(nums.length === 0) return 0;
    
    const dp = Array(nums.length+1);
    
    //Storing both max and min values; 
    dp[0] = [1, 1];
    res = Math.max(...nums);
    
    for(let i = 0; i < nums.length; i++){
        const max_num_prod = nums[i] * dp[i][0];
        const min_num_prod = nums[i] * dp[i][1];
        
        const curr_max = Math.max(max_num_prod, min_num_prod, nums[i]);
        const curr_min = Math.min(max_num_prod, min_num_prod, nums[i]);
        
        dp[i+1] = [curr_max, curr_min];
        res = Math.max(res, curr_max, curr_min);
    }
    console.log(dp);
    return res;
};
