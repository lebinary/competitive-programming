# 70. Climbing Stairs
# Difficulty: Easy
# Status: Accepted
# Runtime: 32 ms (beats 0.1%)
# Memory: 16.7 MB (beats 100.0%)
# Submitted: 2024-09-27 10:24:51 UTC
# URL: https://leetcode.com/submissions/detail/1403826980/

class Solution:
    def climbStairs(self, n: int) -> int:
        dp = {}

        def dfs(step_taken):
            if step_taken > n:
                return 0
            if step_taken == n:
                return 1
            if step_taken in dp:
                return dp[step_taken]

            count1 = dfs(step_taken + 1)
            count2 = dfs(step_taken + 2)
            dp[step_taken] = count1 + count2

            return count1 + count2
        
        res = dfs(0)
        return res

