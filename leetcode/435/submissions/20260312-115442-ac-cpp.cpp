/*
 * 435. Non-overlapping Intervals
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 51 ms (beats 46.0%)
 * Memory: 94 MB (beats 38.7%)
 * Submitted: 2026-03-12 11:54:42 UTC
 * URL: https://leetcode.com/submissions/detail/1945979837/
 */

class Solution {
  public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        int n = intervals.size(), res = 0;
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });

        int prevEnd = INT_MIN;
        for(int i = 0; i < n; ++i) {
            if(intervals[i][0] < prevEnd) res++; 
            else prevEnd = intervals[i][1];
        }

        return res;
    }
};

/**
# Ideas: Interval type 2 - sort by end, find as many non-overlapping as possible
# Approach
- Sort by end
- For each interval:
    if prev.end > interval.start: count++
    else prev = interval
return count
**/

