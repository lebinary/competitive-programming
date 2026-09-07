# 1046. Last Stone Weight
# Difficulty: Easy
# Status: Accepted
# Runtime: 42 ms (beats 0.1%)
# Memory: 16.5 MB (beats 100.0%)
# Submitted: 2024-09-15 12:09:13 UTC
# URL: https://leetcode.com/submissions/detail/1390986173/

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        # lazy solution
        heapq._heapify_max(stones)

        while len(stones) > 1:
            largest = heapq._heappop_max(stones)

            diff = largest - stones[0]
            if diff:
                heapq._heapreplace_max(stones, diff)
            else:
                heapq._heappop_max(stones)

        stones.append(0)
        return stones[0]
