/*
 * 300. Longest Increasing Subsequence
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 504 ms (beats 24.0%)
 * Memory: 296.8 MB (beats 6.9%)
 * Submitted: 2026-01-18 08:00:51 UTC
 * URL: https://leetcode.com/submissions/detail/1888675573/
 */

class Solution {
  public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();

        vector<int> subSequence = {};
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return dfs(dp, nums, n, -1, 0);
    }

    int dfs(vector<vector<int>> &dp, vector<int> &nums, int n, int previ, int i) {
        if (i >= n) return 0;
        if (dp[previ + 1][i] != -1) return dp[previ + 1][i];

        int best = dfs(dp, nums, n, previ, i + 1);
        if (previ == -1 || nums[previ] < nums[i]) {
            best = max(best, 1 + dfs(dp, nums, n, i, i + 1));
        };

        return dp[previ + 1][i] = best;
    }
};
