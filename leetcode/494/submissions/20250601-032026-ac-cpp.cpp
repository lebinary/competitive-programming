/*
 * 494. Target Sum
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 154 ms (beats 32.4%)
 * Memory: 65.3 MB (beats 5.0%)
 * Submitted: 2025-06-01 03:20:26 UTC
 * URL: https://leetcode.com/submissions/detail/1650287412/
 */

class Solution {
public:
    vector<int> nums;
    int target;
    unordered_map<long, int> dp;

    int findTargetSumWays(vector<int>& nums, int target) {
        this->nums = nums;
        this->target = target;

        return dfs(0, 0);    
    }

    long encode(int total, int i) {
        return static_cast<long>(total) << 32 | static_cast<long>(i);
    }

    int dfs(int total, int i) {
        if(i >= nums.size()) {
            if(total == target) return 1;
            return 0;
        }

        long key = encode(total, i);
        if(dp.find(key) != dp.end()) return dp[key];

        int res = dfs(total + nums[i], i + 1) + dfs(total - nums[i], i + 1);
        return dp[key] = res;
    }
};
