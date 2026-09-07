/*
 * 2402. Meeting Rooms III
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 207 ms (beats 7.8%)
 * Memory: 143.3 MB (beats 13.8%)
 * Submitted: 2026-03-12 14:15:02 UTC
 * URL: https://leetcode.com/submissions/detail/1946084897/
 */

class Solution {
  public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        sort(meetings.begin(), meetings.end());

        int m = meetings.size();
        vector<long long> res(n, 0);
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> used;
        priority_queue<int, vector<int>, greater<int>> unused;
        
        for(int i = 0; i < n; ++i) unused.push(i);
        
        for(int i = 0; i < m; ++i) {
            while(!used.empty() && used.top()[0] <= meetings[i][0]) {
                int room = used.top()[1];
                used.pop();
                unused.push(room);
            }

            int room;
            if(!unused.empty()) {
                room = unused.top();
                unused.pop();
                used.push({meetings[i][1], room});
            } else {
                const vector<long long>& top = used.top();
                long long preEndTime = top[0]; 
                room = top[1]; 
                used.pop();

                long long duration = meetings[i][1] - meetings[i][0];
                used.push({preEndTime + duration, room});
            }

            res[room]++;
        }

        int resIdx = 0, hi = INT_MIN;
        for(int i = 0; i < n; ++i) {
            if(res[i] > hi) {
                resIdx = i;
                hi = res[i];
            }
        }

        return resIdx;
    };
};

/**
# Ideas: intervals type 3 - resource allocation
- Sort meetings by start.
- MinHeap store pair<endTime, roomIdx>
- Another minHeap for room, to pick the smallest room 

# Approach:
- Sort by start time
- MinHeap unused, used
- For each itv:
    while used.top.endTime <= curr.startTime:
        room = used.pop
        unused << room
    
    if used.size < n:
        used << { curr.endTime, unused.top }
    else:
        { endTime, room } = used.pop
        duration = curr.endTime - curr.startTime
        used << { endTime + duration, room }
    
    res[unused.top]++
- return max({...res})
    
**/
