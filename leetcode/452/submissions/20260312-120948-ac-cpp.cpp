/*
 * 452. Minimum Number of Arrows to Burst Balloons
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 41 ms (beats 83.6%)
 * Memory: 93.8 MB (beats 83.9%)
 * Submitted: 2026-03-12 12:09:48 UTC
 * URL: https://leetcode.com/submissions/detail/1945989096/
 */

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size(), res = 0;
        sort(points.begin(), points.end(), [&](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });

        long long prevEnd = LLONG_MIN;
        for(int i = 0; i < n; ++i) {
            if(points[i][0] <= prevEnd) continue;
            prevEnd = (long long)points[i][1];
            res++;
        }

        return res;
    }
};

/**
# Ideas: intervals type 2 - maximize non-overlapping

"maximum non-overlaping intervals" = "minimum number of shots"
**/
