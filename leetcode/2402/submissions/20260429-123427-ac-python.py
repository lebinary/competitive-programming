# 2402. Meeting Rooms III
# Difficulty: Hard
# Status: Accepted
# Runtime: 497 ms (beats 5.2%)
# Memory: 50.9 MB (beats 89.4%)
# Submitted: 2026-04-29 12:34:27 UTC
# URL: https://leetcode.com/submissions/detail/1991010702/

class Solution(object):
    def mostBooked(self, n, meetings):
        """
        :type n: int
        :type meetings: List[List[int]]
        :rtype: int
        """
        meetings.sort()
        available, used = [i for i in range(n)], []
        leaderboard = [0] * n

        t, i = meetings[0][0], 0
        while i < len(meetings):
            start, end = meetings[i]
            t = max(t, start)
            duration = end - start

            while used and used[0][0] <= t:
                (_, room_id) = heapq.heappop(used)
                heapq.heappush(available, room_id)

            if available:
                room_id = heapq.heappop(available)
                heapq.heappush(used, (t + duration, room_id))
                leaderboard[room_id] += 1
                i += 1
            else:
                t = used[0][0]

        max_frequency = max(leaderboard)
        room_id = next(i for i, f in enumerate(leaderboard) if f == max_frequency)
        return room_id
        




