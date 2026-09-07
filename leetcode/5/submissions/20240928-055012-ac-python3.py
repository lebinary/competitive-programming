# 5. Longest Palindromic Substring
# Difficulty: Medium
# Status: Accepted
# Runtime: 1662 ms (beats 25.2%)
# Memory: 24.4 MB (beats 11.5%)
# Submitted: 2024-09-28 05:50:12 UTC
# URL: https://leetcode.com/submissions/detail/1404581437/

class Solution:
    def longestPalindrome(self, s: str) -> str:
        # 2D dynamic programming solution
        # Insight: if s[i] == s[j] and dp[i+1][j-1] == True, then s[i: j+1] is palindrome

        N = len(s)
        dp = [[False] * N for _ in range(N)]
        res = [0, 0]

        # each char is itself a palindrome
        for i in range(N):
            dp[i][i] = True
        
        # substring size 2 that is palindrome
        for i in range(N-1):
            if s[i] == s[i+1]:
                dp[i][i+1] = True
                res = [i, i+1]
        
        # now check window size 3 and above
        for diff in range(2, N):
            for i in range(N - diff):
                j = i + diff

                if s[i] == s[j] and dp[i+1][j-1]:
                    dp[i][j] = True
                    res = [i, j]
            
        i, j = res
        return s[i: j+1]
        

