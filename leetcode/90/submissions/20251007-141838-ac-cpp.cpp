/*
 * 90. Subsets II
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 10.3 MB (beats 84.7%)
 * Submitted: 2025-10-07 14:18:39 UTC
 * URL: https://leetcode.com/submissions/detail/1794266200/
 */

class Solution {
  public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> curr;

        dfs(nums, res, curr, 0);
        return res;
    }

    void dfs(vector<int> &nums, vector<vector<int>> &res, vector<int> &curr, int i) {
        if (i >= nums.size()) {
            res.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        dfs(nums, res, curr, i + 1);
        curr.pop_back();

        int j = i + 1;
        while (j < nums.size() && nums[j] == nums[i]) j++;
        dfs(nums, res, curr, j);
    }
};
