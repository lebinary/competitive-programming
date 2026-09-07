/*
 * 40. Combination Sum II
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 854 ms (beats 5.0%)
 * Memory: 14.4 MB (beats 16.0%)
 * Submitted: 2025-07-12 03:51:47 UTC
 * URL: https://leetcode.com/submissions/detail/1694830687/
 */


class Solution {
    int n;
    vector<int> candidates;
    int target;
    vector<vector<int>> res;
    vector<int> comb;

  public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        this->n = candidates.size();
        this->target = target;

        dfs(0, 0);
        return res;
    }

    void dfs(int i, int total) {
        cout << i << ":" << total << endl;
        if (total == target) {
            res.push_back(comb);
            return;
        }
        if (i >= n || total > target) return;

        comb.push_back(candidates[i]);
        dfs(i + 1, total + candidates[i]);
        comb.pop_back();

        while (i + 1 < n && candidates[i] == candidates[i + 1]) i++;
        dfs(i + 1, total);
    }
};
