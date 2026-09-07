# 242. Valid Anagram
# Difficulty: Easy
# Status: Accepted
# Runtime: 39 ms (beats 5.0%)
# Memory: 13.8 MB (beats 16.9%)
# Submitted: 2023-10-16 11:25:39 UTC
# URL: https://leetcode.com/submissions/detail/1076608050/

class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t):
            return False
        
        hm = {}
        for c in s:
            hm[c] = 1 + hm.get(c, 0) 
        print(hm)
        
        for c in t:
            if hm.get(c) and hm.get(c) > 0:
                hm[c] -= 1
            else:
                return False
            
        
        for k, v in hm.items():
            if v != 0:
                return False
        
        return True
