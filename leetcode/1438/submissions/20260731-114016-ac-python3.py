# 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
# Difficulty: Medium
# Status: Accepted
# Runtime: 484 ms (beats 9.9%)
# Memory: 41.7 MB (beats 9.1%)
# Submitted: 2026-07-31 11:40:16 UTC
# URL: https://leetcode.com/submissions/detail/2088745119/

class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        res = 0
        present = [False for _ in range(len(nums))]
        maxHeap, minHeap = [], []

        l = 0
        for r, num in enumerate(nums):
            present[r] = True
            heapq.heappush(maxHeap, (-num, r))
            heapq.heappush(minHeap, (num, r))
            
            while l <= r and maxHeap and minHeap and abs(-maxHeap[0][0] - minHeap[0][0]) > limit:
                present[l] = False
                while maxHeap and not present[maxHeap[0][1]]:
                    heapq.heappop(maxHeap)
                while minHeap and not present[minHeap[0][1]]:
                    heapq.heappop(minHeap)
                l += 1
            
            if r >= l:
                res = max(res, r - l + 1)
        return res
            


