# 3. Longest Substring Without Repeating Characters
# Difficulty: Medium
# Status: Accepted
# Runtime: 54 ms (beats 67.4%)
# Memory: 16.6 MB (beats 100.0%)
# Submitted: 2024-09-12 16:02:21 UTC
# URL: https://leetcode.com/submissions/detail/1387847280/

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        charSet = set()
        l = 0
        res = 0

        for r in range(len(s)):
            while s[r] in charSet:
                charSet.remove(s[l])
                l += 1
            charSet.add(s[r])
            res = max(res, r - l + 1)
        return res
