# 198. House Robber
# Difficulty: Medium
# Status: Accepted
# Runtime: 47 ms (beats 0.6%)
# Memory: 16.5 MB (beats 100.0%)
# Submitted: 2024-09-27 12:02:13 UTC
# URL: https://leetcode.com/submissions/detail/1403888478/

class Solution:
    def rob(self, nums: List[int]) -> int:
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
