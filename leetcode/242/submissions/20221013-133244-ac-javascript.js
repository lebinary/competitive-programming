/*
 * 242. Valid Anagram
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 98 ms (beats 5.7%)
 * Memory: 43.2 MB (beats 100.0%)
 * Submitted: 2022-10-13 13:32:44 UTC
 * URL: https://leetcode.com/submissions/detail/821633392/
 */

/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    if(s.length !== t.length) return false;
    
    const n = s.length; 
    let map = new Map();
    for(let i = 0; i < n; i++){
        if(map.has(s[i])){
            map.set(s[i], map.get(s[i]) + 1);
        }else{
            map.set(s[i], 1);
        }
    }
    
    for(let i = 0; i < n; i++){
        if(map.has(t[i]) && map.get(t[i]) > 0){
            map.set(t[i], map.get(t[i]) - 1);
        }else{
            return false;
        }
    }
    
    return true;
};
