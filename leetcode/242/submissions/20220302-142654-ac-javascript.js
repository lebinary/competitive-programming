/*
 * 242. Valid Anagram
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 102 ms (beats 5.7%)
 * Memory: 43.9 MB (beats 100.0%)
 * Submitted: 2022-03-02 14:26:54 UTC
 * URL: https://leetcode.com/submissions/detail/651948571/
 */

/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    if (s.length !== t.length) return false;
    
    let hm = new Map();
    
    for(let i=0; i < s.length; i++){
        if(hm.get(s[i])){
            hm.set(s[i], hm.get(s[i]) +1);
        }else{
            hm.set(s[i], 1);
        }
    }
    
    for(let i=0; i < t.length; i++){
        if(hm.get(t[i]) && hm.get(t[i]) > 0){
            hm.set(t[i], hm.get(t[i]) -1);
        }else{
            return false;
        }
    }
    
    return true;
};
