# 239. Sliding Window Maximum
# Difficulty: Hard
# Status: Accepted
# Runtime: 1098 ms (beats 5.0%)
# Memory: 32.2 MB (beats 100.0%)
# Submitted: 2024-09-24 09:40:25 UTC
# URL: https://leetcode.com/submissions/detail/1400547203/

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        # solution: keep a monotonically decrement queue, where the leftmost is always the max
        res = []
        q = deque([])

        l = r = 0
        while r < len(nums):
            # before adding, pop all the smaller values
            while q and nums[q[-1]] < nums[r]:
                q.pop()
            q.append(r)

            # remove left value from window
            if l > q[0]:
                q.popleft()
            
            # make sure the window is always size k:
            if (r + 1) >= k:
                res.append(nums[q[0]])
                l += 1
            r += 1
        return res
