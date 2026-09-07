/*
 * 698. Partition to K Equal Sum Subsets
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 11.9 MB (beats 77.9%)
 * Submitted: 2025-05-11 09:56:29 UTC
 * URL: https://leetcode.com/submissions/detail/1630924973/
 */

class Solution {
    vector<bool> used;
    int target;
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % k != 0) return false;

        target = total / k;
        sort(nums.rbegin(), nums.rend());
        used.assign(nums.size(), false);
        return dfs(nums, k, 0, 0);
    }
private:
    bool dfs(vector<int>& nums, int k, int currSum, int start) {
        if (k == 0) return true;
        if (currSum == target) return dfs(nums, k-1, 0, 0);

        for (int i = start; i < nums.size(); i++) {
            int newSum = currSum + nums[i];
            if (used[i] || newSum > target) continue;
            
            used[i] = true;
            if(dfs(nums, k, newSum, i + 1)) return true;
            used[i] = false;

            if(currSum == 0) return false;
        }
        return false;
    }
};
