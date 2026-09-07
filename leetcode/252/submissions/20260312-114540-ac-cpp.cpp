/*
 * 252. Meeting Rooms
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 2 ms (beats 44.1%)
 * Memory: 16 MB (beats 51.7%)
 * Submitted: 2026-03-12 11:45:41 UTC
 * URL: https://leetcode.com/submissions/detail/1945974236/
 */

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        
        for(int i = 0; i < n; ++i) {
            if(i == 0) continue;
            if(intervals[i][0] < intervals[i - 1][1]) return false;
        }

        return true;
    }
};
