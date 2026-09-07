/*
 * 3566. Partition Array into Two Equal Product Subsets
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 201 ms (beats 5.3%)
 * Memory: 70.5 MB (beats 5.3%)
 * Submitted: 2025-06-02 13:39:32 UTC
 * URL: https://leetcode.com/submissions/detail/1651717967/
 */

class Solution {
public:
    unordered_map<string, int> dp;
    vector<int> nums;
    long long target;

    bool checkEqualPartitions(vector<int>& nums, long long target) {
        this->nums = nums;
        this->target = target;

        return dfs(0, 1, 1);
    };

    string hash(int i, long long amountA, long long amountB) {
        return to_string(i) + ":" + to_string(amountA) + ":" + to_string(amountB);
    }

    int dfs(int i, long long amountA, long long amountB) {
        if(i >= nums.size()) {
            return amountA == target && amountB == target;
        }
        if(amountA > target || amountB > target) return 0;

        string k = hash(i, amountA, amountB);
        if(dp.find(k) != dp.end()) return dp[k];

        return dp[k] = dfs(i + 1, amountA * nums[i], amountB) || dfs(i + 1, amountA, amountB * nums[i]);
    }
};
