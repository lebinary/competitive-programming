# 49. Group Anagrams
# Difficulty: Medium
# Status: Accepted
# Runtime: 6 ms (beats 98.8%)
# Memory: 20.4 MB (beats 100.0%)
# Submitted: 2025-03-27 11:37:13 UTC
# URL: https://leetcode.com/submissions/detail/1588040415/

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = {}

        for s in strs:
            sorted_s = ''.join(sorted(s))

            if sorted_s in res:
                res[sorted_s].append(s)
            else:
                res[sorted_s] = [s]

        return list(res.values())
