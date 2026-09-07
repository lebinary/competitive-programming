# 347. Top K Frequent Elements
# Difficulty: Medium
# Status: Accepted
# Runtime: 94 ms (beats 5.2%)
# Memory: 21.2 MB (beats 100.0%)
# Submitted: 2024-09-19 03:15:31 UTC
# URL: https://leetcode.com/submissions/detail/1395016949/

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = {}
        for num in nums:
            count[num] = 1 + count.get(num, 0)
        
        max_heap = [(-freq, key) for key, freq in count.items()]
        heapq.heapify(max_heap)

        res = []

        while k > 0 and len(max_heap) > 0:
            _, key = heapq.heappop(max_heap)
            res.append(key)
            k -= 1
        
        return res
