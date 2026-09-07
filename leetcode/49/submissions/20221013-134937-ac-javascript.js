/*
 * 49. Group Anagrams
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 272 ms (beats 5.1%)
 * Memory: 53.1 MB (beats 100.0%)
 * Submitted: 2022-10-13 13:49:37 UTC
 * URL: https://leetcode.com/submissions/detail/821642910/
 */

/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    let res = {};
    for(s of strs){
        const count = new Array(26).fill(0);
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
