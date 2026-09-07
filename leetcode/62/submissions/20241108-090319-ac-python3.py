# 62. Unique Paths
# Difficulty: Medium
# Status: Accepted
# Runtime: 0 ms (beats 100.0%)
# Memory: 16.6 MB (beats 100.0%)
# Submitted: 2024-11-08 09:03:19 UTC
# URL: https://leetcode.com/submissions/detail/1446591649/

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        # bottom up approach
        dp = [[0] * (n + 1) for _ in range(m + 1)]

        # destination
        dp[m-1][n-1] = 1
        
        # calculate the rest of the graph
        for r in range(m-1, -1, -1):
            for c in range(n-1, -1, -1):
                # curr cell = bottom cell + right cell
                dp[r][c] += dp[r+1][c] + dp[r][c+1]

        return dp[0][0]
