/*
 * 70. Climbing Stairs
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 64 ms (beats 1.3%)
 * Memory: 42 MB (beats 100.0%)
 * Submitted: 2022-02-24 10:31:26 UTC
 * URL: https://leetcode.com/submissions/detail/648029414/
 */

/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    let dp = new Array(n+1);
    
    dp[n] = 1;
    dp[n-1] = 1;
    
    for(let i = n-2; i >= 0; i--){
        dp[i] = dp[i+1] + dp[i+2];
    }
    
    return dp[0];
};
