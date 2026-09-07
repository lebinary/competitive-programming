/*
 * 62. Unique Paths
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 9.2 MB (beats 68.9%)
 * Submitted: 2025-08-14 14:16:54 UTC
 * URL: https://leetcode.com/submissions/detail/1735011384/
 */

class Solution {
  public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        dp[m - 1][n - 1] = 1;

        for (int r = m - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {
                dp[r][c] += dp[r + 1][c] + dp[r][c + 1];
            }
        }

        return dp[0][0];
    }
};
