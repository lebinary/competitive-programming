/*
 * 5. Longest Palindromic Substring
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 403 ms (beats 11.8%)
 * Memory: 291.9 MB (beats 7.7%)
 * Submitted: 2026-01-21 11:44:27 UTC
 * URL: https://leetcode.com/submissions/detail/1892080502/
 */

class Solution {
  public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        pair<int, int> res = {0, 0};

        for (int l = 0; l < n; ++l) {
            for (int r = l; r < n; ++r) {
                dfs(s, res, dp, l, r);
            }
        }
        return s.substr(res.first, res.second - res.first + 1);
    };

    bool dfs(string &s, pair<int, int> &res, vector<vector<int>> &dp, int l, int r) {
        if (l > r) return 1;
        if (l == r) return 1;
        if (dp[l][r] != -1) return dp[l][r];

        bool isPal = s[l] == s[r] && dfs(s, res, dp, l + 1, r - 1);
        if (isPal && r - l + 1 > res.second - res.first + 1) res = {l, r};

        return dp[l][r] = isPal;
    }
};

