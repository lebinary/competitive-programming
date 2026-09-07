# 424. Longest Repeating Character Replacement
# Difficulty: Medium
# Status: Accepted
# Runtime: 137 ms (beats 31.7%)
# Memory: 16.7 MB (beats 100.0%)
# Submitted: 2024-09-19 10:36:01 UTC
# URL: https://leetcode.com/submissions/detail/1395328188/

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        hm = [0] * 26
        res = 0

        l = 0
        for r in range(len(s)):
            r_idx = ord(s[r]) - ord('A')
            hm[r_idx] += 1

            while (r + 1 - l) - max(hm) > k:
                l_idx = ord(s[l]) - ord('A')
                hm[l_idx] -= 1
                l += 1

            res = max(res, r + 1 - l)

        return res
