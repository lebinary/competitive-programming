/*
 * 960. Delete Columns to Make Sorted III
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 7 ms (beats 44.9%)
 * Memory: 17.7 MB (beats 12.6%)
 * Submitted: 2025-12-22 09:52:53 UTC
 * URL: https://leetcode.com/submissions/detail/1862281332/
 */

class Solution {
  public:
    int R, C;
    int minDeletionSize(vector<string> &strs) {
        this->R = strs.size(), this->C = strs[0].size();
        vector<vector<int>> dp(C + 1, vector<int>(C, -1));
        return dfs(strs, dp, -1, 0);
    }

    int dfs(vector<string> &strs, vector<vector<int>> &dp, int prevC, int c) {
        if (c >= C) return 0;
        int prevI = prevC + 1;
        if (dp[prevI][c] != -1) return dp[prevI][c];

        bool isValid = true;
        if (prevC >= 0) {
            for (int r = 0; r < R; ++r) {
                if (strs[r][c] < strs[r][prevC]) {
                    isValid = false;
                    break;
                }
            }
        }

        int best = 1 + dfs(strs, dp, prevC, c + 1);
        if (isValid) best = min(best, dfs(strs, dp, c, c + 1));

        return dp[prevI][c] = best;
    }
};

