/*
 * 46. Permutations
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 10.7 MB (beats 41.0%)
 * Submitted: 2026-01-24 08:46:07 UTC
 * URL: https://leetcode.com/submissions/detail/1895132901/
 */


class Solution {
  public:
    vector<vector<int>> permute(vector<int> &nums) {
        int n = nums.size();
        vector<int> perm;
        vector<bool> chosen(n, false);
        vector<vector<int>> res;

        dfs(res, nums, perm, chosen);
        return res;
    }

    void dfs(vector<vector<int>> &res, vector<int> &nums, vector<int> &perm, vector<bool> &chosen) {
        if (perm.size() >= nums.size()) {
            res.push_back(perm);
            return;
        };

        for (int i = 0; i < nums.size(); ++i) {
            if (chosen[i]) continue;

            chosen[i] = true;
            perm.push_back(nums[i]);
            dfs(res, nums, perm, chosen);
            perm.pop_back();
            chosen[i] = false;
        }
    }
};
