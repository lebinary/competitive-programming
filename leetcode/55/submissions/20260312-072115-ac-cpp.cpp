/*
 * 55. Jump Game
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 753 ms (beats 5.0%)
 * Memory: 55.9 MB (beats 6.0%)
 * Submitted: 2026-03-12 07:21:15 UTC
 * URL: https://leetcode.com/submissions/detail/1945780081/
 */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return dfs(nums, dp, n, 0);
    }

    bool dfs(vector<int>& nums, vector<int>& dp, int n, int i) {
        if(i >= n) return dp[i] = false;
        if(i == n - 1) return dp[i] = true;
        if(nums[i] == 0) return dp[i] = false;
        if(dp[i] != -1) return dp[i];

        for(int j = i + 1; j <= i + nums[i]; ++j) {
            if(dfs(nums, dp, n, j)) return dp[i] = true;
        }

        return dp[i] = false;
    }
};

/**
# Ideas:
- Essentially a shortest path problem: find shortest path from 0 to (n - 1)

# Approach 1: BFS - because weight equals => MLE

# Approach 2: DFS
    dfs(i):
        if i >= n: return false
        if i == n - 1: return true

        res = false
        for(j := i + 1 -> i + nums[i])
            res |= dfs(j)
        return res
**/
