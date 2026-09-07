# 239. Sliding Window Maximum
# Difficulty: Hard
# Status: Accepted
# Runtime: 1367 ms (beats 5.0%)
# Memory: 41.6 MB (beats 8.4%)
# Submitted: 2024-09-24 09:51:03 UTC
# URL: https://leetcode.com/submissions/detail/1400555519/

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        res = []
        max_heap = []

        l = 0
        for r, num in enumerate(nums):
            heapq.heappush(max_heap, (-num, r))

            # make sure we have processed at least k elements before shrinking
            if (r + 1) >= k:
                # remove left value from window
                while max_heap and l > max_heap[0][1]:
                    heapq.heappop(max_heap)

                # The maximum element is at the top of the heap
                res.append(-max_heap[0][0])
                l += 1
        
        return res

