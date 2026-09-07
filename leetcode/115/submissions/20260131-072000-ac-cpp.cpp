/*
 * 115. Distinct Subsequences
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 43 ms (beats 11.9%)
 * Memory: 26.9 MB (beats 72.6%)
 * Submitted: 2026-01-31 07:20:00 UTC
 * URL: https://leetcode.com/submissions/detail/1902732506/
 */

class Solution {
  public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return dfs(dp, s, t, n, m, 0, 0);
    }

    int dfs(vector<vector<int>> &dp, string &s, string &t, int n, int m, int i, int j) {
        if (j >= m) return 1;
        if (i >= n) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int agg = 0;
        if (s[i] == t[j]) agg += dfs(dp, s, t, n, m, i + 1, j + 1);
        agg += dfs(dp, s, t, n, m, i + 1, j);

        return dp[i][j] = agg;
    }
};
