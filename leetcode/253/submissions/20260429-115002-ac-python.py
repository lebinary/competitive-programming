# 253. Meeting Rooms II
# Difficulty: Medium
# Status: Accepted
# Runtime: 10 ms (beats 27.0%)
# Memory: 14.2 MB (beats 89.5%)
# Submitted: 2026-04-29 11:50:02 UTC
# URL: https://leetcode.com/submissions/detail/1990986990/

class Solution(object):
    def minMeetingRooms(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        intervals.sort()
        rooms = 0
        used = []

        for (start, end) in intervals:
            while used and used[0] <= start:
                heapq.heappop(used)
            
            heapq.heappush(used, end)
            rooms = max(rooms, len(used))
        
        return rooms

        
