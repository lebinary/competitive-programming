# 424. Longest Repeating Character Replacement
# Difficulty: Medium
# Status: Accepted
# Runtime: 165 ms (beats 33.4%)
# Memory: 13.9 MB (beats 81.0%)
# Submitted: 2022-03-01 13:55:01 UTC
# URL: https://leetcode.com/submissions/detail/651261410/

class Solution(object):
    def characterReplacement(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        res = 1
        l = 0
        
        count = {}
        
        for r in range(len(s)):
            count[s[r]] = 1 + count.get(s[r], 0)
            
            while (r-l+1) - max(count.values()) > k:
                count[s[l]] -= 1
                l += 1
            
            res = max(res, r-l+1)
            
        
        return res
