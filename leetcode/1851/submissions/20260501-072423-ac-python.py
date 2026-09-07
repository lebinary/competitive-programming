# 1851. Minimum Interval to Include Each Query
# Difficulty: Hard
# Status: Accepted
# Runtime: 502 ms (beats 35.6%)
# Memory: 61 MB (beats 15.3%)
# Submitted: 2026-05-01 07:24:23 UTC
# URL: https://leetcode.com/submissions/detail/1992374230/

class Solution(object):
    def minInterval(self, intervals, queries):
        """
        :type intervals: List[List[int]]
        :type queries: List[int]
        :rtype: List[int]
        """
        res = [-1] * len(queries)
        intervals.sort()
        queries_with_index = sorted([(q, i) for i, q in enumerate(queries)])
        candidates = []

        j = 0
        for q, i in queries_with_index:            
            while j < len(intervals) and intervals[j][0] <= q:
                size = intervals[j][1] - intervals[j][0] + 1
                heapq.heappush(candidates, (size, j))
                j += 1
            
            while candidates and intervals[candidates[0][1]][1] < q:
                heapq.heappop(candidates)
            
            if candidates:
                res[i] = candidates[0][0]
        
        return res
            

            
[7,9,3,9,3]
            
[3,3,7,9,9]
[[1,6],[1,9],[4,5],[5,8],[8,10]]
