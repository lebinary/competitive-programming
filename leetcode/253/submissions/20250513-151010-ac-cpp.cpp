/*
 * 253. Meeting Rooms II
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 19 ms (beats 5.9%)
 * Memory: 41 MB (beats 5.0%)
 * Submitted: 2025-05-13 15:10:11 UTC
 * URL: https://leetcode.com/submissions/detail/1632923566/
 */

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int L = numeric_limits<int>::max(), R = numeric_limits<int>::min();
        for (auto& interval : intervals) {
            L = min(L, interval[0]);
            R = max(R, interval[1]);
        }

        vector<int> changes(R-L+1, 0);
        for (auto& interval : intervals) {
            changes[interval[0] - L]++;
            changes[interval[1] - L]--;
        }

        int res = 0;
        int curr = 0;
        for (int change : changes) {
            curr += change;
            res = max(res, curr);
        }

        return res;
    }
};
