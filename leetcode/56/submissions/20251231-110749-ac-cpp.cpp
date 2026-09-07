/*
 * 56. Merge Intervals
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 3 ms (beats 89.1%)
 * Memory: 23.9 MB (beats 59.9%)
 * Submitted: 2025-12-31 11:07:49 UTC
 * URL: https://leetcode.com/submissions/detail/1870215501/
 */

class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;

        for (vector<int> &itv : intervals) {
            if (!res.empty() && itv[0] <= res.back()[1]) {
                res.back()[1] = max(res.back()[1], itv[1]);
            } else {
                res.push_back(itv);
            }
        }

        return res;
    }
};

