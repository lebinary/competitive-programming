# 213. House Robber II
# Difficulty: Medium
# Status: Accepted
# Runtime: 38 ms (beats 0.6%)
# Memory: 16.9 MB (beats 100.0%)
# Submitted: 2024-09-28 03:29:16 UTC
# URL: https://leetcode.com/submissions/detail/1404494327/

class Solution:
    def rob(self, nums: List[int]) -> int:
        # solution, run dfs on 2 subarrays nums[:N-1] and nums[1:]
        N = len(nums)

        if N == 1: return nums[0]

        return max(self.max_rob(nums[:N-1]), self.max_rob(nums[1:]))
    
    def max_rob(self, nums):
        # solution, run dfs on 2 subarrays nums[:N-1] and nums[1:]
        N = len(nums)

        # top down
        dp = {}

        def dfs(i):
            if i >= N:
                return 0
            if i in dp:
                return dp[i]
            if N - 2 <= i < N:
                return nums[i]
            
            max_rob = nums[i] + max([dfs(j) for j in range(i+2, N)])
            dp[i] = max_rob

            return max_rob
            
        res = 0
        for i in range(N):
            res = max(res, dfs(i))

        return res
