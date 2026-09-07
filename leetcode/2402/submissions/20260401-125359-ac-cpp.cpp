/*
 * 2402. Meeting Rooms III
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 79 ms (beats 86.6%)
 * Memory: 125.6 MB (beats 93.5%)
 * Submitted: 2026-04-01 12:53:59 UTC
 * URL: https://leetcode.com/submissions/detail/1965832845/
 */

class Solution {
  public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        vector<int> rooms(n, 0);
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> unused;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> used;

        for(int i = 0; i < n; ++i) unused.push(i);

        for(auto& meeting : meetings) {
            long long start = meeting[0], end = meeting[1];
            long long duration = end - start;

            // cleaning step
            while(!used.empty() && used.top().first <= start) {
                auto [prevEnd, roomNum] = used.top();
                used.pop();
                unused.push(roomNum);
            }

            if(!unused.empty()) {
                int roomNum = unused.top();
                unused.pop();

                used.push({end, roomNum});
                rooms[roomNum]++;
            } else {
                auto [prevEnd, roomNum] = used.top();
                used.pop();

                used.push({prevEnd + duration, roomNum});
                rooms[roomNum]++;
            }
        }

        auto it = max_element(rooms.begin(), rooms.end());
        return it - rooms.begin();
    };
};

/**
[[18,19],[3,12],[17,19],[2,13],[7,10]]

n = 4

used = [[2,13], [3,12], [7,10], ]

[[2,13], [3,12], [7,10], [17,19], [18,19]]

**/


/**
# Approach:
unused heap: take room with the lowest number => heap for room number
used heap: store the room being used => heap for {endTime, roomNumber}
for each sorted meeting by start time:
    duration, endTime = current meeting

    clearning: any room that becomes available now should move over 

    if there are no available room in unused heap:
        [prevEndTime, roomNumer] = pop from used heap
        
        endTime = prevEndTime + duration
        push roomNumber on to unused heap

    smallestRoomNumer = pop from unsued heap
    push {endTime, smallestRoomNumber}
**/












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
    
    if unused not empty:
        used << { curr.endTime, unused.top }
    else:
        { endTime, room } = used.pop
        duration = curr.endTime - curr.startTime
        used << { endTime + duration, room }
    
    res[unused.top]++
- return max({...res})
    
**/
