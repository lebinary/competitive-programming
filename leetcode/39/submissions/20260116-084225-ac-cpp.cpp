/*
 * 39. Combination Sum
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 3 ms (beats 51.5%)
 * Memory: 14.4 MB (beats 39.2%)
 * Submitted: 2026-01-16 08:42:26 UTC
 * URL: https://leetcode.com/submissions/detail/1886622406/
 */

class Solution {
  public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<int> comb;

        dfs(candidates, comb, 0, target, 0);
        return res;
    }

    void dfs(vector<int> &candidates, vector<int> &comb, int total, int target, int i) {
        if (total > target || i >= candidates.size()) return;
        if (total == target) {
            res.push_back(comb);
            return;
        }

        comb.push_back(candidates[i]);
        dfs(candidates, comb, total + candidates[i], target, i);
        comb.pop_back();

        dfs(candidates, comb, total, target, i + 1);
    }
};
