/*
 * 55. Jump Game
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 734 ms (beats 5.0%)
 * Memory: 57.4 MB (beats 6.0%)
 * Submitted: 2025-05-21 10:28:48 UTC
 * URL: https://leetcode.com/submissions/detail/1640198242/
 */

class Solution {
    vector<int> nums;
    vector<int> dp;
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        this->nums = nums;
        this->dp.assign(n, -1);

        return dfs(0);
    }
private:
    bool dfs(int i) {
        if (i >= nums.size()) return 0;
        if (i == nums.size() - 1) return 1;
        if (nums[i] == 0) return dp[i] = 0;
        if (dp[i] != -1) return dp[i];

        for(int dist = 1; dist <= nums[i]; ++dist) {
            if(dfs(i + dist)) return dp[i] = 1;
        }

        return dp[i] = 0;
    }
};
