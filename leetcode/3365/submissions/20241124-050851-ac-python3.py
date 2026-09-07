# 3365. Rearrange K Substrings to Form Target String
# Difficulty: Medium
# Status: Accepted
# Runtime: 192 ms (beats 50.5%)
# Memory: 24.9 MB (beats 67.0%)
# Submitted: 2024-11-24 05:08:51 UTC
# URL: https://leetcode.com/submissions/detail/1461385691/

class Solution:
    def isPossibleToRearrange(self, s: str, t: str, k: int) -> bool:
        n = len(s)
        s_dict = {}
        t_dict = {}

        for i in range(0, n, n//k):
            s_key = s[i : i+ (n//k)]
            s_dict[s_key] = s_dict.get(s_key, 0) + 1

            t_key = t[i : i+ (n//k)]
            t_dict[t_key] = t_dict.get(t_key, 0) + 1

        return s_dict == t_dict
