/*
 * 49. Group Anagrams
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 221 ms (beats 5.1%)
 * Memory: 53.8 MB (beats 100.0%)
 * Submitted: 2022-05-02 03:38:52 UTC
 * URL: https://leetcode.com/submissions/detail/691348841/
 */

/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    
    let res = {};
    
    for(s of strs){
        // Use an array count as id for anagrams
        count = new Array(26).fill(0);
        for(let i = 0; i < s.length; i++){
            count[s.charCodeAt(i) - "a".charCodeAt(0)] += 1;
        }
        
        if(res[count]){
            res[count].push(s);
        }else{
            res[count] = [s];
        }
    }
    
    return Object.values(res);
};
