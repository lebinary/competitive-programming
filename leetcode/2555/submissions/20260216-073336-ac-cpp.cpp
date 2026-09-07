/*
 * 2555. Maximize Win From Two Segments
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 595 ms (beats 5.2%)
 * Memory: 67.6 MB (beats 13.0%)
 * Submitted: 2026-02-16 07:33:37 UTC
 * URL: https://leetcode.com/submissions/detail/1920784183/
 */

class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size(), res = 0;
        vector<vector<int>> intervals;

        int l = 0;
        for(int r = 0; r < n; ++r) {
            while(l <= r && prizePositions[r] - prizePositions[l] > k) {
                l++;
            }

            if(r < n - 1 && prizePositions[r+1] - prizePositions[l] <= k) continue;
            intervals.push_back({l, r});
        }

        if(intervals.size() == 1) return intervals[0][1] - intervals[0][0] + 1;
        
        for(int i = 0; i < intervals.size(); ++i) {
            for(int j = i + 1; j < intervals.size(); ++j) {
                int len = 0;
                if(intervals[i][1] >= intervals[j][0]) {
                    len = intervals[j][1] - intervals[i][0] + 1;
                } else {
                    len = intervals[i][1] - intervals[i][0] + 1 + intervals[j][1] - intervals[j][0] + 1;
                }
                res = max(res, len);
            }
        }

        return res;
    }
};

/**



[1,1,2,2,3,3,5,8,8,9] k=2

[0,5]
[4,6]
[7,]






**/
