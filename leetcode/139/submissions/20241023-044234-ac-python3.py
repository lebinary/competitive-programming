# 139. Word Break
# Difficulty: Medium
# Status: Accepted
# Runtime: 3 ms (beats 72.1%)
# Memory: 16.6 MB (beats 100.0%)
# Submitted: 2024-10-23 04:42:34 UTC
# URL: https://leetcode.com/submissions/detail/1431093974/

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        dp = [False] * (len(s) + 1)
        dp[-1] = True # base case

        for i in range(len(s)-1, -1, -1):
            for w in wordDict:
                if i + len(w) <= len(s) and s[i : i+len(w)] == w:
                    dp[i] = dp[i + len(w)]
                if dp[i]:
                    break
        return dp[0]
