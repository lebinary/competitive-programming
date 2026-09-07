# 746. Min Cost Climbing Stairs
# Difficulty: Easy
# Status: Accepted
# Runtime: 58 ms (beats 6.5%)
# Memory: 16.8 MB (beats 100.0%)
# Submitted: 2024-09-27 11:29:44 UTC
# URL: https://leetcode.com/submissions/detail/1403868331/

class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        N = len(cost)

        # bottom up
        dp = [0] * N
        dp[-1] = cost[-1]
        dp[-2] = cost[-2]

        for i in range(N - 3, -1, -1):
            dp[i] = min(cost[i] + dp[i+1], cost[i] + dp[i+2])

        return min(dp[0], dp[1])
