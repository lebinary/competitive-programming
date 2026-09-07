# 213. House Robber II
# Difficulty: Medium
# Status: Accepted
# Runtime: 42 ms (beats 0.6%)
# Memory: 16.5 MB (beats 100.0%)
# Submitted: 2024-09-28 03:35:24 UTC
# URL: https://leetcode.com/submissions/detail/1404497302/

class Solution:
    def rob(self, nums: List[int]) -> int:
        # solution, run dfs on 2 subarrays nums[:N-1] and nums[1:]
        N = len(nums)

        if N == 1: return nums[0]

        return max(self.max_rob(nums[:N-1]), self.max_rob(nums[1:]))
    
    def max_rob(self, nums):
        # bottom up
        rob1, rob2 = 0, 0
        for num in nums:
            new_rob = max(rob1 + num, rob2)
            rob1 = rob2
            rob2 = new_rob

        return rob2 
