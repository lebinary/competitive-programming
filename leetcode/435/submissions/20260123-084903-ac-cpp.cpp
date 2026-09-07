/*
 * 435. Non-overlapping Intervals
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 44 ms (beats 60.8%)
 * Memory: 94 MB (beats 38.7%)
 * Submitted: 2026-01-23 08:49:04 UTC
 * URL: https://leetcode.com/submissions/detail/1894141106/
 */

class Solution {
  public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });

        int n = intervals.size(), res = 0;
        vector<int> &last = intervals[0];
        for (int i = 1; i < n; ++i) {
            vector<int> &curr = intervals[i];
            if (curr[0] < last[1]) {
                res++;
            } else {
                last = curr;
            }
        }

        return res;
    }
};

