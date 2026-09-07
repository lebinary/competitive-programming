# 242. Valid Anagram
# Difficulty: Easy
# Status: Accepted
# Runtime: 28 ms (beats 9.1%)
# Memory: 15.1 MB (beats 8.6%)
# Submitted: 2023-10-16 11:28:40 UTC
# URL: https://leetcode.com/submissions/detail/1076609691/

class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t):
            return False
        
        hashmapS = {}
        hashmapT = {}
        for i in range(len(s)):
            hashmapS[s[i]] = 1 + hashmapS.get(s[i], 0)
            hashmapT[t[i]] = 1 + hashmapT.get(t[i], 0)

        return hashmapS == hashmapT
