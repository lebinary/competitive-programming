/*
 * 238. Product of Array Except Self
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 117 ms (beats 5.3%)
 * Memory: 54.2 MB (beats 100.0%)
 * Submitted: 2022-10-20 14:52:08 UTC
 * URL: https://leetcode.com/submissions/detail/826664227/
 */

/**
 * @param {number[]} nums
 * @return {number[]}
 */


/***
Example: [-1, 1, 0, -3, 3]

prefix:  [-1, -1, 6, 24]

posfix:  [24, 24, 12, 4]

return:  [24, 12, 8,  6]

***/
var productExceptSelf = function(nums) {
    const n = nums.length;
    
    // Calculate prefix
    let prefix = new Array(n).fill(1);
    for(let i = 0; i < n; i++){
        if(i === 0) {
            prefix[i] = nums[i];
        }else{
            prefix[i] = prefix[i-1] * nums[i];
        } 
    }
    console.log("prefix", prefix);
    
    // Calculate posfix
    let posfix = new Array(n).fill(1);
    for(let i = n-1; i >= 0; i--){
        if(i === n-1){
            posfix[i] = nums[i];
        }else{
            posfix[i] = posfix[i+1] * nums[i];
        }
    }
    console.log("posfix", posfix);
    
    // Calculate result
    let res = new Array(n);
    res[0] = posfix[1];
    res[n-1] = prefix[n-2];
    for(let i = 1; i < n-1; i++){
        res[i] = prefix[i-1] * posfix[i+1];
    }
    console.log("res", res);
    
    return res;
};
