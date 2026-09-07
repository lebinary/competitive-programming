# 424. Longest Repeating Character Replacement
# Difficulty: Medium
# Status: Accepted
# Runtime: 121 ms (beats 35.3%)
# Memory: 16.6 MB (beats 100.0%)
# Submitted: 2024-09-12 15:58:54 UTC
# URL: https://leetcode.com/submissions/detail/1387843608/

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        res = 0
        hm = {}

        l = 0
        for r in range(len(s)):
            hm[s[r]] = 1 + hm.get(s[r], 0)

            # shrink window if minimum_replacement_count > k:
            # replacement_count = window_length - maximum_occurence
            while (r + 1 - l) - max(hm.values()) > k:
                hm[s[l]] -= 1
                l += 1
            
            # update result
            res = max(res, r + 1 - l)
        
        return res
