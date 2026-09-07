# 242. Valid Anagram
# Difficulty: Easy
# Status: Accepted
# Runtime: 55 ms (beats 6.0%)
# Memory: 16.8 MB (beats 100.0%)
# Submitted: 2024-09-06 04:16:27 UTC
# URL: https://leetcode.com/submissions/detail/1380663025/

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t): return False

        hm = {}
        for c in s:
            if c not in hm:
                hm[c] = 1
            else:
                hm[c] += 1

        for c in t:
            if c not in hm:
                return False
            else:
                hm[c] -= 1
        

        return all(val == 0 for val in hm.values())
