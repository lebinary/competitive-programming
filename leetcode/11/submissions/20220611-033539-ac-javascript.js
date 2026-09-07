/*
 * 11. Container With Most Water
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 127 ms (beats 5.1%)
 * Memory: 49.8 MB (beats 100.0%)
 * Submitted: 2022-06-11 03:35:39 UTC
 * URL: https://leetcode.com/submissions/detail/719294202/
 */

/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let l = 0;
    let r = height.length - 1;
    
    let maxArea = 0;
    while(l < r){
        maxArea = Math.max(maxArea, Math.min(height[l], height[r]) * (r-l));
        if(height[l] <= height[r]){
            l++;
        }else{
            r--;
        }
    }
    
    return maxArea;
};
