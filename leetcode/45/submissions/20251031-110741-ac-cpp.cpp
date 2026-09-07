/*
 * 45. Jump Game II
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 64 ms (beats 19.1%)
 * Memory: 21.4 MB (beats 25.5%)
 * Submitted: 2025-10-31 11:07:42 UTC
 * URL: https://leetcode.com/submissions/detail/1816777534/
 */

class Solution {
  public:
    int jump(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp = vector<int>(n, n);
        dp[n - 1] = 0;

        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= nums[i]; ++j) {
                if(i + j >= n) break;
                dp[i] = min(dp[i], dp[i + j] + 1);
            }
        }

        return dp[0];
    }
};
