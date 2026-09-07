/*
 * 698. Partition to K Equal Sum Subsets
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 2889 ms (beats 5.0%)
 * Memory: 12.1 MB (beats 51.5%)
 * Submitted: 2025-05-11 09:54:31 UTC
 * URL: https://leetcode.com/submissions/detail/1630923813/
 */

class Solution {
    vector<bool> used;
    int target;

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;

        target = sum / k;
        sort(nums.rbegin(), nums.rend());
        used.assign(nums.size(), false);
        return backtrack(nums, k, 0, 0);
    }

private:
    bool backtrack(vector<int>& nums, int k, int currentSum, int start) {
        if (k == 0) return true;
        if (currentSum == target) return backtrack(nums, k - 1, 0, 0);

        for (int i = start; i < nums.size(); i++) {
            if (used[i] || currentSum + nums[i] > target) continue;
            used[i] = true;
            if (backtrack(nums, k, currentSum + nums[i], i + 1)) return true;
            used[i] = false;
        }
        return false;
    }
};
