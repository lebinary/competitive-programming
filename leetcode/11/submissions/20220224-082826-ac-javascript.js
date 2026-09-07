/*
 * 11. Container With Most Water
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 94 ms (beats 5.1%)
 * Memory: 49.5 MB (beats 100.0%)
 * Submitted: 2022-02-24 08:28:26 UTC
 * URL: https://leetcode.com/submissions/detail/647988241/
 */

/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let max_area = 0;
    
    l = 0;
    r = height.length - 1;
    
    while(l < r){
        let curr_area = 0
        
        if(height[l] < height[r]){
            curr_area = height[l] * (r-l);
            l++;
        }else{
            curr_area = height[r] * (r-l);
            r--;
        }
        
        max_area = Math.max(max_area, curr_area);
    }
    
    return max_area;
};
