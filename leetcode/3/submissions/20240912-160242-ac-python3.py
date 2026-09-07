# 3. Longest Substring Without Repeating Characters
# Difficulty: Medium
# Status: Accepted
# Runtime: 163 ms (beats 63.3%)
# Memory: 16.6 MB (beats 100.0%)
# Submitted: 2024-09-12 16:02:42 UTC
# URL: https://leetcode.com/submissions/detail/1387847655/

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) <= 1: return len(s)
        
        res = 0
        l = 0
        for r in range(len(s)):
          # find right mmost index of s[r] in current s[l:r]
          idx = -1
          for i in range(r-1, l-1, -1):
            if s[i] == s[r]:
              idx = i
              break

          # if found index, shrink left of s[l:r] until that index
          if idx != -1:
            l = idx + 1
          
          res = max(res, r + 1 - l)

        return res
