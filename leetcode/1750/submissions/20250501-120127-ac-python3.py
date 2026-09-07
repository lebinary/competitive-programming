# 1750. Minimum Length of String After Deleting Similar Ends
# Difficulty: Medium
# Status: Accepted
# Runtime: 41 ms (beats 10.2%)
# Memory: 17.9 MB (beats 100.0%)
# Submitted: 2025-05-01 12:01:28 UTC
# URL: https://leetcode.com/submissions/detail/1622753598/

class Solution:
    def minimumLength(self, s: str) -> int:
        l, r = 0, len(s) - 1

        while l < r:
            if s[l] != s[r]:
                break

            prev = s[l]
            while l < len(s) and s[l] == prev:
                prev = s[l]
                l += 1

            prev = s[r]
            while r >= 0 and s[r] == prev:
                prev = s[r]
                r -= 1
        return max(0, r - l + 1)
