# 5. Longest Palindromic Substring
# Difficulty: Medium
# Status: Accepted
# Runtime: 274 ms (beats 54.3%)
# Memory: 16.8 MB (beats 100.0%)
# Submitted: 2024-09-28 05:33:44 UTC
# URL: https://leetcode.com/submissions/detail/1404569394/

class Solution:
    def longestPalindrome(self, s: str) -> str:
        def expand(l, r):
            while l >= 0 and r < len(s) and s[l] == s[r]:
                l -= 1
                r += 1
            
            return r - l - 1


        resLen = 0
        res = [0, 0]
        for i in range(len(s)):
            odd_length = expand(i, i)
            if odd_length > resLen:
                resLen = odd_length
                half = odd_length // 2
                res = [i - half, i + half]
            
            even_length = expand(i, i + 1)
            if even_length > resLen:
                resLen = even_length
                half = even_length // 2
                res = [i - half + 1, i + half]
        
        i, j = res
        return s[i: j+1]
        

