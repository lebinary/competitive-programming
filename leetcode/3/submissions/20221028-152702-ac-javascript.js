/*
 * 3. Longest Substring Without Repeating Characters
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 129 ms (beats 11.7%)
 * Memory: 43.9 MB (beats 100.0%)
 * Submitted: 2022-10-28 15:27:02 UTC
 * URL: https://leetcode.com/submissions/detail/832130832/
 */

/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    if(s.length < 2) return s.length;
    
    let l = 0;
    let r = 1;
    let longestStr = 0;
    
    while(r < s.length){
        for(let i = l; i < r; i++){
            if(s[i] === s[r]) {
                longestStr = Math.max(longestStr, r - l);
                l = i+1;
            }    
        }
        r++;
    }
    
    longestStr = Math.max(longestStr, r - l);

    return longestStr;
};
