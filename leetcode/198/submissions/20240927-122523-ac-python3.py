# 198. House Robber
# Difficulty: Medium
# Status: Accepted
# Runtime: 35 ms (beats 0.6%)
# Memory: 16.6 MB (beats 100.0%)
# Submitted: 2024-09-27 12:25:23 UTC
# URL: https://leetcode.com/submissions/detail/1403903036/

class Solution:
    def rob(self, nums: List[int]) -> int:
        # bottom up, in order
        N = len(nums)

        for i in range(1, N):
            if i == 1:
                nums[i] = max(nums[i], nums[i-1])
            else:
                nums[i] = max(nums[i] + nums[i-2], nums[i-1])

        return nums[-1]
