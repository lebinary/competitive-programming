/*
 * 213. House Robber II
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 10.9 MB (beats 37.8%)
 * Submitted: 2026-01-19 12:46:07 UTC
 * URL: https://leetcode.com/submissions/detail/1889844486/
 */

class Solution {
  public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        vector<int> dp(n + 1, -1);
        int best = dfs(nums, dp, n - 1, 0);
        dp.assign(n + 1, -1);
        best = max(best, dfs(nums, dp, n, 1));
        return best;
    }

    int dfs(vector<int> &nums, vector<int> &dp, int n, int i) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];

        return dp[i] = max(nums[i] + dfs(nums, dp, n, i + 2), dfs(nums, dp, n, i + 1));
    }
};
