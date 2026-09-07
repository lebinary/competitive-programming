# 1750. Minimum Length of String After Deleting Similar Ends
# Difficulty: Medium
# Status: Accepted
# Runtime: 30 ms (beats 31.4%)
# Memory: 18.2 MB (beats 100.0%)
# Submitted: 2025-05-01 12:04:34 UTC
# URL: https://leetcode.com/submissions/detail/1622755437/

class Solution:
    def minimumLength(self, s: str) -> int:
        l, r = 0, len(s) - 1

        while l < r and s[l] == s[r]:
            prev = s[l]
            while l <= r and s[l] == prev:
                l += 1
            while l <= r and s[r] == prev:
                r -= 1

        return r - l + 1
