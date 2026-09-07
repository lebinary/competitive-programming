# 3. Longest Substring Without Repeating Characters
# Difficulty: Medium
# Status: Accepted
# Runtime: 56 ms (beats 67.4%)
# Memory: 16.6 MB (beats 100.0%)
# Submitted: 2024-09-12 16:14:51 UTC
# URL: https://leetcode.com/submissions/detail/1387860543/

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) <= 1: return len(s)
        hm = {} # maps character -> most recent idx 

        res = 0
        l = 0
        for r in range(len(s)):
            if s[r] in hm and hm[s[r]] >= l:
                l = hm[s[r]] + 1

            res = max(res, r + 1 - l)

            hm[s[r]] = r

        return res
