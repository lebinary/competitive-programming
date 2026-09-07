/*
 * 198. House Robber
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 10.7 MB (beats 23.9%)
 * Submitted: 2025-06-01 04:07:52 UTC
 * URL: https://leetcode.com/submissions/detail/1650340056/
 */

class Solution {
public:
    vector<int> dp;
    vector<int> nums;

    int rob(vector<int>& nums) {
        int n = nums.size();
        this->nums = nums;
        this->dp.assign(n + 1, -1);

        return dfs(0);
    }

    int dfs(int i) {
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int res = max(nums[i] + dfs(i + 2), dfs(i + 1));
        return dp[i] = res;
    }
};
