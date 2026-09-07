/*
 * 5. Longest Palindromic Substring
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 663 ms (beats 10.5%)
 * Memory: 305.7 MB (beats 5.1%)
 * Submitted: 2026-01-21 11:42:32 UTC
 * URL: https://leetcode.com/submissions/detail/1892079139/
 */


class Solution {
  public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        string res{s[0]};

        for (int l = 0; l < n; ++l) {
            for (int r = l; r < n; ++r) {
                dfs(s, res, dp, l, r);
            }
        }
        return res;
    };

    bool dfs(string &s, string &res, vector<vector<int>> &dp, int l, int r) {
        if (l > r) return 1;
        if (l == r) return 1;
        if (dp[l][r] != -1) return dp[l][r];

        bool isPal = s[l] == s[r] && dfs(s, res, dp, l + 1, r - 1);
        if (isPal && r - l + 1 > res.size()) res = s.substr(l, r - l + 1);

        return dp[l][r] = isPal;
    }
};
