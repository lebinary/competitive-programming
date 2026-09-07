/*
 * 72. Edit Distance
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 7 ms (beats 61.3%)
 * Memory: 13 MB (beats 74.2%)
 * Submitted: 2025-08-31 10:49:12 UTC
 * URL: https://leetcode.com/submissions/detail/1754653295/
 */

class Solution {
  public:
    vector<vector<int>> dp;
    int minDistance(string word1, string word2) {
        this->dp.resize(word1.size(), vector<int>(word2.size(), -1));
        return dfs(word1, word2, 0, 0);
    }

    int dfs(string &word1, string &word2, int i, int j) {
        if (i >= word1.size() && j >= word2.size()) return 0;
        if (i >= word1.size()) return word2.size() - j;
        if (j >= word2.size()) return word1.size() - i;
        if (dp[i][j] != -1) return dp[i][j];

        if (word1[i] == word2[j]) return dp[i][j] = dfs(word1, word2, i + 1, j + 1);

        int best = INT_MAX;
        // insert
        best = min(best, 1 + dfs(word1, word2, i, j + 1));

        // remove
        best = min(best, 1 + dfs(word1, word2, i + 1, j));

        // replace
        best = min(best, 1 + dfs(word1, word2, i + 1, j + 1));

        return dp[i][j] = best;
    }
};
