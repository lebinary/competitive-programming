/*
 * 78. Subsets
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 10.1 MB (beats 37.4%)
 * Submitted: 2026-03-28 13:35:46 UTC
 * URL: https://leetcode.com/submissions/detail/1961773312/
 */

class Solution {
    vector<vector<int>> res;
    vector<int> subset;

public:
    vector<vector<int>> subsets(vector<int>& nums) {    
        dfs(nums, 0);
        return res;
    }

    void dfs(auto& nums, int i) {
        if(i >= nums.size()) {
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        dfs(nums, i + 1);
        subset.pop_back();

        dfs(nums, i + 1);
    }
};
