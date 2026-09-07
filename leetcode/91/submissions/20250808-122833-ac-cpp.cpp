/*
 * 91. Decode Ways
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 8.8 MB (beats 46.0%)
 * Submitted: 2025-08-08 12:28:34 UTC
 * URL: https://leetcode.com/submissions/detail/1727928578/
 */


class Solution {
  public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp = vector<int>(n + 1, -1);
        dp[n] = 1;

        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') {
                dp[i] = 0;
                continue;
            };

            dp[i] = dp[i + 1];
            if (s[i] == '1' && i + 1 < n)
                dp[i] += dp[i + 2];
            else if (s[i] == '2' && i + 1 < n && (s[i + 1] - '0') <= 6)
                dp[i] += dp[i + 2];
        }

        return dp[0];
    }
};
