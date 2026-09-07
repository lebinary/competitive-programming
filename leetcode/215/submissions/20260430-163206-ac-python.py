# 215. Kth Largest Element in an Array
# Difficulty: Medium
# Status: Accepted
# Runtime: 534 ms (beats 52.6%)
# Memory: 21.8 MB (beats 11.4%)
# Submitted: 2026-04-30 16:32:07 UTC
# URL: https://leetcode.com/submissions/detail/1991955344/

class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums_heap = []
        for num in nums:
            heapq.heappush(nums_heap, -num)
        
        for i in range(1, k):
            heapq.heappop(nums_heap)
        
        return -nums_heap[0]
