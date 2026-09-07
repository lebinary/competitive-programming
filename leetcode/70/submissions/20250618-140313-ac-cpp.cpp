/*
 * 70. Climbing Stairs
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 8.5 MB (beats 38.9%)
 * Submitted: 2025-06-18 14:03:13 UTC
 * URL: https://leetcode.com/submissions/detail/1668353965/
 */

class Solution {
public:
    vector<int> dp;
    int climbStairs(int n) {
        this->dp.assign(n + 1, -1);
        return dfs(0, n);
    }

    int dfs(int i, int n) {
        if(i > n) return 0;
        if(i == n) return 1;
        if(dp[i] != -1) return dp[i];
        return dp[i] = dfs(i + 1, n) + dfs(i + 2, n);
    }
};
