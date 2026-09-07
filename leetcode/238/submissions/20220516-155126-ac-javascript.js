/*
 * 238. Product of Array Except Self
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 264 ms (beats 5.3%)
 * Memory: 54.4 MB (beats 100.0%)
 * Submitted: 2022-05-16 15:51:26 UTC
 * URL: https://leetcode.com/submissions/detail/700780810/
 */

/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function(nums) {
    // prefix = [ 1,  2,  6, 24]
    // posfix = [24, 24, 12, 4 ]
    // res    = [24, 12, 8 ,  ]
    const n = nums.length;
    
    let prefix = new Array(4).fill(1);
    for(let i = 0; i < n; i++){
        if(i == 0){
            prefix[i] = nums[i];
            continue;
        }
        prefix[i] = nums[i] * prefix[i-1]; 
    }
    
    let posfix = new Array(4).fill(1);
    for(let i = n-1; i >= 0; i--){
        if(i == n-1){
            posfix[i] = nums[i];
            continue;
        }
        posfix[i] = nums[i] * posfix[i+1];
    }
    
    res = new Array(n);
    for(let i = 0; i < n; i++){
        if(i == 0){
            res[i] = posfix[i+1]; 
        }
        else if(i == n-1){
            res[i] = prefix[i-1];
        }
        else {
            res[i] = prefix[i-1] * posfix[i+1];
        }
    }
    
    return res;
};
