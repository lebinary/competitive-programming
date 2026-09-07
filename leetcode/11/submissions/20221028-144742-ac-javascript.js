/*
 * 11. Container With Most Water
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 142 ms (beats 5.1%)
 * Memory: 50 MB (beats 100.0%)
 * Submitted: 2022-10-28 14:47:42 UTC
 * URL: https://leetcode.com/submissions/detail/832109152/
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
        let currArea = Math.min(height[l], height[r]) * (r - l);
        maxArea = Math.max(currArea, maxArea);
        
        if(height[l] < height[r]) l++;
        else r--;
    }
    
    return maxArea;
};
