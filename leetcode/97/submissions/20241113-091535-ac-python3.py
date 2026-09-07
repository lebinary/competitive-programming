# 97. Interleaving String
# Difficulty: Medium
# Status: Accepted
# Runtime: 44 ms (beats 89.2%)
# Memory: 16.8 MB (beats 100.0%)
# Submitted: 2024-11-13 09:15:35 UTC
# URL: https://leetcode.com/submissions/detail/1451448336/

class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s1) + len(s2) != len(s3):
            return False

        n = len(s1)
        m = len(s2)
        
        # Bottom-up:
        dp = [[False] * (m + 1) for _ in range(n + 1)] 
        dp[n][m] = True

        # go up the recursive tree
        for i in range(n, -1, -1):
            for j in range(m, -1, -1):
                # skip base case
                if i == n and j == m:
                    continue

                k = i + j
                if i < n and s1[i] == s3[k]:
                    dp[i][j] |= dp[i+1][j]
                
                if j < m and s2[j] == s3[k]:
                    dp[i][j] |= dp[i][j+1]

        return dp[0][0]
