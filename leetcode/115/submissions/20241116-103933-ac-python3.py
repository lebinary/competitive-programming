# 115. Distinct Subsequences
# Difficulty: Hard
# Status: Accepted
# Runtime: 505 ms (beats 28.4%)
# Memory: 73.4 MB (beats 59.1%)
# Submitted: 2024-11-16 10:39:33 UTC
# URL: https://leetcode.com/submissions/detail/1454235005/

class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        # bottom-up
        n = len(s)
        m = len(t)

        dp = [[0] * (m+1) for _ in range(n+1)]

        for i in range(n, -1, -1):
            for j in range(m, -1, -1):
                if j == m:
                    dp[i][j] = 1
                elif i == n:
                    dp[i][j] = 0
                else:
                    dp[i][j] = dp[i+1][j]
                    if s[i] == t[j]:
                        dp[i][j] += dp[i+1][j+1]
        
        return dp[0][0]
