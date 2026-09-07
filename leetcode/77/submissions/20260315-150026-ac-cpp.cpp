/*
 * 77. Combinations
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 35 ms (beats 90.5%)
 * Memory: 62.3 MB (beats 99.2%)
 * Submitted: 2026-03-15 15:00:27 UTC
 * URL: https://leetcode.com/submissions/detail/1949194652/
 */

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> comb(k, 0);
        backtrack(res, comb, 0, 1, n);
        return res;
    }

    void backtrack(vector<vector<int>>& res, vector<int>& comb, int i, int nStart, int nEnd) {
        if(i >= comb.size()) {
            res.push_back(comb);
            return;
        }

        for(int v = nStart; v <= nEnd; ++v) {
            comb[i] = v;
            backtrack(res, comb, i + 1, v + 1, nEnd);
            comb[i] = 0;
        }
    }
};
