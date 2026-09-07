/*
 * 253. Meeting Rooms II
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 2 ms (beats 59.1%)
 * Memory: 16.2 MB (beats 53.4%)
 * Submitted: 2026-03-12 08:23:51 UTC
 * URL: https://leetcode.com/submissions/detail/1945820121/
 */

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });
        priority_queue<int, vector<int>, greater<int>> endTimeHeap;

        for(int i = 0; i < n; ++i) {
            if(!endTimeHeap.empty() && intervals[i][0] >= endTimeHeap.top()) {
                endTimeHeap.pop();
            }
            endTimeHeap.push(intervals[i][1]);
        }

        return endTimeHeap.size();
    }
};

/**
# Ideas
- Intervals type 3: resource allocation

# Approach:
- Sort by start
- For each interval:
    if overlap minHeap.top: pop
    push
- return heap.size

**/
