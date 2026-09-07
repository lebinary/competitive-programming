# 3208. Alternating Groups II
# Difficulty: Medium
# Status: Accepted
# Runtime: 731 ms (beats 14.8%)
# Memory: 21.9 MB (beats 99.1%)
# Submitted: 2025-04-19 14:17:49 UTC
# URL: https://leetcode.com/submissions/detail/1611552828/

class Solution:
    def numberOfAlternatingGroups(self, colors: List[int], k: int) -> int:
        colors = colors + colors[:k-1]
        n = len(colors)

        res = 0
        l, r = 0, 1

        while r < n:
            if colors[r] == colors[r-1]:
                l = r
                r += 1
                continue
            
            r += 1
            if r - l < k: # window too small
                continue
            
            res += 1
            l += 1
        return res

        




