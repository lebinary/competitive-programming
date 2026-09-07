/*
 * 15. 3Sum
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 196 ms (beats 9.5%)
 * Memory: 53 MB (beats 100.0%)
 * Submitted: 2022-02-24 07:50:08 UTC
 * URL: https://leetcode.com/submissions/detail/647972313/
 */

/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    nums.sort((a,b) => a-b);
    let res = [];

    for(let i = 0; i < nums.length-2; i++){
        if(i > 0 && nums[i] == nums[i-1]){
            continue;   
        }
        
        l = i+1
        r = nums.length-1;
        
        while(l < r){
            const three_sum = nums[i] + nums[l] + nums[r];
            
            if(three_sum > 0) r--;
            else if(three_sum < 0) l++;
            else{
                res.push([nums[i], nums[l], nums[r]]);
                l++;
                while(nums[l] === nums[l-1] && l < r){
                    l++;
                }
            }
        }
    }
    return res
};
