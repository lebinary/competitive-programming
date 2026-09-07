/*
 * 91. Decode Ways
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 8.7 MB (beats 63.9%)
 * Submitted: 2025-08-08 12:05:18 UTC
 * URL: https://leetcode.com/submissions/detail/1727911941/
 */


class Solution {
  public:
    vector<int> dp;

    int numDecodings(string s) {
        int n = s.size();
        this->dp.resize(n + 1, -1);
        return dfs(s, 0);
    }

    int dfs(string &s, int i) {
        if (i >= s.size()) return 1;
        if (s[i] == '0') return 0;
        if (dp[i] != -1) return dp[i];

        int count = 0;
        if (s[i] == '1' && i + 1 < s.size()) {
            count += dfs(s, i + 2);
        } else if (s[i] == '2' && i + 1 < s.size() && (s[i + 1] - '0') <= 6) {
            count += dfs(s, i + 2);
        }
        count += dfs(s, i + 1);

        return dp[i] = count;
    }
};
