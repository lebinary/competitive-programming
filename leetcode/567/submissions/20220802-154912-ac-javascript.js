/*
 * 567. Permutation in String
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 9987 ms (beats 5.0%)
 * Memory: 56.4 MB (beats 81.2%)
 * Submitted: 2022-08-02 15:49:12 UTC
 * URL: https://leetcode.com/submissions/detail/763354023/
 */

/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var checkInclusion = function(s1, s2) {
    const n1 = s1.length;
    const n2 = s2.length;
    
    const sortedS1 = s1.split("").sort().join("");
    
    for(let i = 0; i <= (n2-n1); i++){
        const sortedSubS2 = s2.substring(i, i+n1).split("").sort().join("");
        if(sortedS1 === sortedSubS2){
            return true;
        }
    }
    
    return false;
};
