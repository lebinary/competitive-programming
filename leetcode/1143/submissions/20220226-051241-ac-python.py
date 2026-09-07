# 1143. Longest Common Subsequence
# Difficulty: Medium
# Status: Accepted
# Runtime: 341 ms (beats 99.3%)
# Memory: 22.4 MB (beats 86.0%)
# Submitted: 2022-02-26 05:12:41 UTC
# URL: https://leetcode.com/submissions/detail/649033023/

class Solution(object):
    def longestCommonSubsequence(self, text1, text2):
        """
        :type text1: str
        :type text2: str
        :rtype: int
        """
        dp = [[0 for j in range(len(text2) + 1)] for i in range(len(text1) + 1)]
        
        for i in range(len(text1)-1, -1, -1):
            for j in range(len(text2)-1, -1, -1):
                if text1[i] == text2[j]:
                    dp[i][j] = dp[i+1][j+1] + 1
                else:
                    dp[i][j] = max(dp[i][j+1], dp[i+1][j])
        
        return dp[0][0]
