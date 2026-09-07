/*
 * 198. House Robber
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 72 ms (beats 2.6%)
 * Memory: 38.6 MB (beats 100.0%)
 * Submitted: 2021-11-02 13:34:52 UTC
 * URL: https://leetcode.com/submissions/detail/580974811/
 */

/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {    
    // [rob1, rob2, n, n+1, ...]
    // rob1 and rob2 represent maxes to that points
    
    let rob1 = 0;
    let rob2 = 0;
    for(let n of nums){
        temp = Math.max(rob1 + n, rob2);
        rob1 = rob2;
        rob2 = temp;
    }
    
    return rob2;
};
