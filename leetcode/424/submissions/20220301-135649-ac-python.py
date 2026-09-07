# 424. Longest Repeating Character Replacement
# Difficulty: Medium
# Status: Accepted
# Runtime: 125 ms (beats 86.0%)
# Memory: 14 MB (beats 81.0%)
# Submitted: 2022-03-01 13:56:49 UTC
# URL: https://leetcode.com/submissions/detail/651262174/

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
        maxF = 0
        for r in range(len(s)):
            count[s[r]] = 1 + count.get(s[r], 0)
            
            #Optimize
            maxF = max(maxF, count[s[r]])
            
            while (r-l+1) - maxF > k:
                count[s[l]] -= 1
                l += 1
            
            res = max(res, r-l+1)
            
        
        return res
