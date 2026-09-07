/*
 * 91. Decode Ways
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 8.7 MB (beats 46.0%)
 * Submitted: 2026-01-03 09:22:43 UTC
 * URL: https://leetcode.com/submissions/detail/1872904049/
 */

class Solution {
  public:
    vector<int> dp;
    int numDecodings(string s) {
        int n = s.size();
        this->dp.resize(n + 1, -1);

        return dfs(s, dp, n, 0);
    }

    bool valid(char l, char r) {
        if (l != '1' && l != '2') return false;
        if (l == '2' && (r == '7' || r == '8' || r == '9')) return false;
        return true;
    }

    int dfs(string &s, vector<int> &dp, int n, int i) {
        if (i >= n) return 1;
        if (s[i] == '0') return 0;
        if (dp[i] != -1) return dp[i];

        int count = 0;
        count += dfs(s, dp, n, i + 1);

        if (i < n - 1 && valid(s[i], s[i + 1])) {
            count += dfs(s, dp, n, i + 2);
        }

        return dp[i] = count;
    };
};
