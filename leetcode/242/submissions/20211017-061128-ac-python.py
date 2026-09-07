# 242. Valid Anagram
# Difficulty: Easy
# Status: Accepted
# Runtime: 32 ms (beats 5.1%)
# Memory: 14 MB (beats 16.5%)
# Submitted: 2021-10-17 06:11:28 UTC
# URL: https://leetcode.com/submissions/detail/572515187/

class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t): return False
        
        hm = {}
        for char in s:
            if char in hm: hm[char] += 1
            else: hm[char] = 1
                
        for char in t:
            if char in hm and hm[char] > 0: hm[char] -= 1
            else: return False
        
        return True
