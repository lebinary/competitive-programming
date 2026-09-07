# 746. Min Cost Climbing Stairs
# Difficulty: Easy
# Status: Accepted
# Runtime: 55 ms (beats 6.5%)
# Memory: 19.1 MB (beats 96.5%)
# Submitted: 2024-09-27 11:18:18 UTC
# URL: https://leetcode.com/submissions/detail/1403861178/

class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        dp = {}

        def dfs(i):
            if i == len(cost):
                return 0
            if i > len(cost):
                return float('inf')
            if i in dp:
                return dp[i]
            
            # min cost to reach the top from this position
            minCost = cost[i] + min(dfs(i + 1), dfs(i + 2))

            # store in dp
            dp[i] = minCost

            return minCost
        
        return min(dfs(0), dfs(1))
