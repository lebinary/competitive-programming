/*
 * 57. Insert Interval
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 21.8 MB (beats 22.1%)
 * Submitted: 2026-03-12 11:35:21 UTC
 * URL: https://leetcode.com/submissions/detail/1945967710/
 */

class Solution {
  public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        int n = intervals.size();
        if(n == 0) return { newInterval };
        vector<vector<int>> res;

        int i = 0;
        while(i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }

        res.push_back(newInterval);

        while(i < n) {
            if(overlap(res.back(), intervals[i])) {
                res.back()[0] = min(res.back()[0], intervals[i][0]);
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            } else {
                res.push_back(intervals[i]);
            }
            i++;
        }
        return res;
    }

    bool overlap(vector<int>& a, vector<int>& b) {
        if(a[1] < b[0] || b[1] < a[0]) return false;
        return a[0] <= b[1] || a[1] >= b[0];
    }
};

/**
Approach: intervals type 1
- Loop through intervals, insert all inteval s.t itv.end < newItv.start
- Insert newItv
- For subsequent itv, check if overlap: merge else just append
**/
