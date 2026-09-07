/*
 * 15. 3Sum
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 247 ms (beats 9.2%)
 * Memory: 52.9 MB (beats 100.0%)
 * Submitted: 2022-10-26 15:45:56 UTC
 * URL: https://leetcode.com/submissions/detail/830792074/
 */

/**
 * @param {number[]} nums
 * @return {number[][]}
 */

/***
[-4, -1, -1, 0, 1, 2]

***/
var threeSum = function(nums) {
    nums.sort((a,b) => a - b);
    
    let res = [];
    
    for(let i = 0; i < nums.length - 2; i++){
        if(i > 0 && nums[i] === nums[i-1]) continue;
        
        let l = i+1;
        let r = nums.length - 1;
        while(l < r){
            let threeSum = nums[i] + nums[l] + nums[r];
            
            if(threeSum === 0) {
                res.push([nums[i], nums[l], nums[r]]);
                l++;
                
                while(nums[l] === nums[l-1] && l < r) l++;
            }
            else if(threeSum < 0) l++;
            else r--;
        }
    }
    
    return res;
};
