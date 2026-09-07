/*
 * 1353. Maximum Number of Events That Can Be Attended
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 63 ms (beats 45.5%)
 * Memory: 75 MB (beats 31.5%)
 * Submitted: 2026-03-12 09:54:58 UTC
 * URL: https://leetcode.com/submissions/detail/1945896583/
 */

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size(), res = 0;
        sort(events.begin(), events.end());
        int maxDay = 0;
        for (int i = 0; i < events.size(); i++) {
            maxDay = max(maxDay, events[i][1]);
        }
        priority_queue<int, vector<int>, greater<int>> endTimeHeap;

        int j = 0;
        for(int i = 0; i <= maxDay; ++i) {
            // push avai events on heap
            while(j < n && events[j][0] <= i) {
                endTimeHeap.push(events[j][1]);
                j++;
            }

            // clear expired events
            while(!endTimeHeap.empty() && endTimeHeap.top() < i) endTimeHeap.pop();

            // attend event with earliest end time
            if(!endTimeHeap.empty()) {
                endTimeHeap.pop();
                res++;
            }
        }

        return res;
    }
};

/**
# Ideas: for each day, need to figure out maximum events can attend

# Approach: greedy, scan through the day, check what events available, pick the one with ealiest end time
- sort by start, init the heap to store end time
- for each DAY:
    push avai events on minHeap
    clear expired events
    pick minHeap.top event - earliest to end, so that maximize time avai for more events
- return res 
**/
