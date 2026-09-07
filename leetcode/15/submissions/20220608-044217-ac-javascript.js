/*
 * 15. 3Sum
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 203 ms (beats 9.4%)
 * Memory: 52.3 MB (beats 100.0%)
 * Submitted: 2022-06-08 04:42:17 UTC
 * URL: https://leetcode.com/submissions/detail/717043845/
 */

/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    nums.sort((a, b) => a - b);
    let res = [];
    for(let i = 0; i < nums.length-2; i++){
        if(i > 0 && nums[i] == nums[i-1]){
            continue;   
        }
        
        let l = i+1
        let r = nums.length-1;
        
        while(l < r){
            let three_sum = nums[i] + nums[l] + nums[r];
            if(three_sum === 0){
                res.push([nums[i], nums[l], nums[r]]);
                l++;
                while(nums[l] === nums[l-1] && l < r){
                    l++;
                }
            }else if(three_sum < 0){
                l++;
            }else{
                r--;
            }
        }
    }
    
    return res;
};
