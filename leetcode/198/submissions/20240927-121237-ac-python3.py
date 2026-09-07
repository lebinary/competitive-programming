# 198. House Robber
# Difficulty: Medium
# Status: Accepted
# Runtime: 38 ms (beats 0.6%)
# Memory: 16.5 MB (beats 100.0%)
# Submitted: 2024-09-27 12:12:37 UTC
# URL: https://leetcode.com/submissions/detail/1403895014/

class Solution:
    def rob(self, nums: List[int]) -> int:
        # bottom up
        N = len(nums)
        dp = nums.copy()

        for i in range(N-3, -1, -1):
            dp[i] = nums[i] + max([dp[j] for j in range(i+2, N)])
        
        return max(dp)
