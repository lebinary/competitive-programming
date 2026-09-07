# 10. Regular Expression Matching
# Difficulty: Hard
# Status: Accepted
# Runtime: 7 ms (beats 57.6%)
# Memory: 16.7 MB (beats 100.0%)
# Submitted: 2024-11-23 09:16:08 UTC
# URL: https://leetcode.com/submissions/detail/1460630889/

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m = len(s)
        n = len(p)
        dp = [[False] * (n+1) for _ in range(m+1)]
        
        # base case
        dp[m][n] = True

        for i in range(m, -1, -1):
            for j in range(n-1, -1, -1):
                if j < n and p[j] == "*":
                    continue

                matched = i < m and (s[i] == p[j] or p[j] == ".")
                if j + 1 < n and p[j+1] == "*":
                    dp[i][j] = (dp[i][j+2] or               # dont use "*"
                                (matched and dp[i+1][j]))     # use "*"
                elif matched:
                    dp[i][j] = dp[i+1][j+1]

        return dp[0][0]
