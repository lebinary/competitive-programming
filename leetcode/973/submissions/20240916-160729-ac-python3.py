# 973. K Closest Points to Origin
# Difficulty: Medium
# Status: Accepted
# Runtime: 592 ms (beats 5.0%)
# Memory: 22.9 MB (beats 100.0%)
# Submitted: 2024-09-16 16:07:29 UTC
# URL: https://leetcode.com/submissions/detail/1392273238/

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        # min heap problem
        # turn points into minheap, where sorted by the euclidean length to origin
        # while k > 0: pop off the heap
        min_heap = []
        for p in points:
            dist = p[0]**2 + p[1]**2
            min_heap.append((dist, p[0], p[1]))

        heapq.heapify(min_heap)
        res = []
        for _ in range(k):
            _, x, y = heapq.heappop(min_heap)
            res.append([x, y])
        
        return res
