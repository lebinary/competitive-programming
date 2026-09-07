/*
 * 3. Longest Substring Without Repeating Characters
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 131 ms (beats 11.5%)
 * Memory: 47.3 MB (beats 100.0%)
 * Submitted: 2022-06-12 10:17:29 UTC
 * URL: https://leetcode.com/submissions/detail/720372591/
 */

/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let maxLength = 0;
    
    let tmp = "";
    for(let i = 0; i < s.length; i ++){    
        let index = tmp.indexOf(s[i]);
        if(i > 0 && index > -1){
            tmp = tmp.slice(index+1);
        }
        
        tmp += s[i];
        maxLength = Math.max(maxLength, tmp.length);
    }
    
    return maxLength;
};
