# 3. Longest Substring Without Repeating Characters
# Difficulty: Medium
# Status: Accepted
# Runtime: 72 ms (beats 62.3%)
# Memory: 14.3 MB (beats 38.7%)
# Submitted: 2022-02-28 10:50:42 UTC
# URL: https://leetcode.com/submissions/detail/650519240/

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        charSet = set()
        
        l = 0
        res = 0
        
        for r in range(0, len(s)):
            while s[r] in charSet:
                charSet.remove(s[l])
                l += 1
                
            charSet.add(s[r])
            res = max(res, r - l + 1)
            
        return res
            
