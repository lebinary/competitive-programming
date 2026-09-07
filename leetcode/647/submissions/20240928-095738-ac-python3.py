# 647. Palindromic Substrings
# Difficulty: Medium
# Status: Accepted
# Runtime: 165 ms (beats 34.5%)
# Memory: 16.5 MB (beats 100.0%)
# Submitted: 2024-09-28 09:57:38 UTC
# URL: https://leetcode.com/submissions/detail/1404750510/

class Solution:
    def countSubstrings(self, s: str) -> int:        
        res = 0
        for i in range(len(s)):
            l = i
            r = i
            while l >= 0 and r < len(s) and s[l] == s[r]:
                res += 1
                l -= 1
                r += 1

            l = i
            r = i + 1
            while l >= 0 and r < len(s) and s[l] == s[r]:
                res += 1
                l -= 1
                r += 1
        
        return res
