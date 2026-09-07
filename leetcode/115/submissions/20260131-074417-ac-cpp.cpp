/*
 * 115. Distinct Subsequences
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 31 ms (beats 53.5%)
 * Memory: 44.1 MB (beats 38.6%)
 * Submitted: 2026-01-31 07:44:18 UTC
 * URL: https://leetcode.com/submissions/detail/1902752261/
 */

class Solution {
  public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<unsigned long>> dp(n + 1, vector<unsigned long>(m + 1, 0));

        for (int i = 0; i <= n; ++i) {
            dp[i][m] = 1;
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                dp[i][j] += dp[i + 1][j];
                if (s[i] == t[j]) dp[i][j] += dp[i + 1][j + 1];
            }
        }

        return dp[0][0];
    }
};

