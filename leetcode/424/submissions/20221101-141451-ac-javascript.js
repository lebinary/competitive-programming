/*
 * 424. Longest Repeating Character Replacement
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 510 ms (beats 5.0%)
 * Memory: 48.6 MB (beats 100.0%)
 * Submitted: 2022-11-01 14:14:51 UTC
 * URL: https://leetcode.com/submissions/detail/834691641/
 */

/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var characterReplacement = function(s, k) {
    let res = 1;
    let l = 0;
    let maxF = 0;
    let count = {};
    
    for(let r = 0; r < s.length; r++){
        if(count[s[r]] !== undefined) count[s[r]] += 1;
        else count[s[r]] = 1;
        
        let count_arr = Object.values(count);
        maxF = Math.max(maxF, ...count_arr);
        
        while(r - l + 1 - maxF > k){
            count[s[l]] -= 1;
            l += 1;
        }
        
        res = Math.max(res, r - l + 1);
    }
    
    return res;
};
