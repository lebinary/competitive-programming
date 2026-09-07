/*
 * 198. House Robber
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 10.7 MB (beats 46.8%)
 * Submitted: 2025-06-01 03:59:50 UTC
 * URL: https://leetcode.com/submissions/detail/1650333838/
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 2, 0);

        for(int i = n - 1; i >= 0; --i) {
            dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
        }

        return dp[0];
    }
};
