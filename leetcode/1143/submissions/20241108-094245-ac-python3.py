# 1143. Longest Common Subsequence
# Difficulty: Medium
# Status: Accepted
# Runtime: 398 ms (beats 39.7%)
# Memory: 41.9 MB (beats 82.1%)
# Submitted: 2024-11-08 09:42:45 UTC
# URL: https://leetcode.com/submissions/detail/1446617314/

class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        '''
        Intuition: looking at the dfs solution
        def dfs(i, j):
            if i == len(text1) or j == len(text2):
                return 0
            if text1[i] == text2[j]:
                return 1 + dfs(i + 1, j + 1)
            return max(dfs(i + 1, j), dfs(i, j + 1))
        
        We can see that to get the answer, we need to either:
        1. solve a sub-problem diagonally if text1[i] == text2[j]
        2. solve a sub-problem with right and bottom cell if text1[i] != text2[j]
        '''

        m = len(text1)
        n = len(text2)

        # bottom up approach
        dp = [[0] * (n+1) for _ in range(m+1)]

        for i in range(m-1, -1, -1):
            for j in range(n-1, -1, -1):
                if text1[i] == text2[j]:
                    dp[i][j] = 1 + dp[i+1][j+1]
                else:
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1])

        return dp[0][0]
