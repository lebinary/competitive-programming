/*
 * 253. Meeting Rooms II
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 3 ms (beats 53.1%)
 * Memory: 16 MB (beats 94.7%)
 * Submitted: 2026-04-01 10:55:13 UTC
 * URL: https://leetcode.com/submissions/detail/1965756128/
 */

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> endTime;
        
        for(int i = 0; i < n; ++i) {
            if(!endTime.empty() && endTime.top() <= intervals[i][0]) {
                endTime.pop();
            }

            endTime.push(intervals[i][1]);
        }

        return endTime.size();
    }
};

/**
# Ideas
- Intervals type 3: resource allocation

# Approach:
- Sort by start
- For each interval:
    if not overlap minHeap.top: pop // means earliest-ending meeting room dont overlap with current => reuse
    push
- return heap.size


[0,5,15]

[10,20,30]
**/
