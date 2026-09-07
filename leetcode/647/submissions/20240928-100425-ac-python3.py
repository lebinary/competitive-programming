# 647. Palindromic Substrings
# Difficulty: Medium
# Status: Accepted
# Runtime: 233 ms (beats 24.7%)
# Memory: 24.6 MB (beats 21.4%)
# Submitted: 2024-09-28 10:04:25 UTC
# URL: https://leetcode.com/submissions/detail/1404754870/

class Solution:
    def countSubstrings(self, s: str) -> int:
        N = len(s)
        res = 0

        # 2D dynamic programming
        dp = [[False] * N for _ in range(N)]

        # size 1 substring are all palindrome
        for i in range(N):
            res += 1
            dp[i][i] = True
        
        # size 2 substring, possible palindrome
        for i in range(N-1):
            if s[i] == s[i+1]:
                res += 1
                dp[i][i+1] = True
            
        # size 3 and above, check palindrome
        for diff in range(2, N):
            for i in range(N-diff):
                j = i + diff

                if s[i] == s[j] and dp[i+1][j-1]:
                    res += 1
                    dp[i][j] = True
        
        return res
