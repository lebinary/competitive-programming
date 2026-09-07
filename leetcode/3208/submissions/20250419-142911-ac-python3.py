# 3208. Alternating Groups II
# Difficulty: Medium
# Status: Accepted
# Runtime: 751 ms (beats 10.2%)
# Memory: 21.3 MB (beats 100.0%)
# Submitted: 2025-04-19 14:29:12 UTC
# URL: https://leetcode.com/submissions/detail/1611561647/

class Solution:
    def numberOfAlternatingGroups(self, colors: List[int], k: int) -> int:
        n = len(colors)

        res = 0
        l = 0

        for r in range(1, n + k - 1):
            if colors[r % n] == colors[(r - 1) % n]:
                l = r
                continue
            
            if r - l + 1 == k:
                res += 1
                l += 1
        return res

        




