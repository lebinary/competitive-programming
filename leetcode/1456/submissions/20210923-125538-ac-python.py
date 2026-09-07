# 1456. Maximum Number of Vowels in a Substring of Given Length
# Difficulty: Medium
# Status: Accepted
# Runtime: 148 ms (beats 23.3%)
# Memory: 17.4 MB (beats 7.1%)
# Submitted: 2021-09-23 12:55:38 UTC
# URL: https://leetcode.com/submissions/detail/559722799/

class Solution(object):
    def maxVowels(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        vowels = 0
        for i in range(0, k):
            if s[i] in "aeiou": vowels +=1
        
        maxVowels = vowels
        for i in range(k, len(s)):
            if s[i] in "aeiou": vowels +=1
            if s[i-k] in "aeiou": vowels -=1
            maxVowels = max(maxVowels, vowels)
            
        return maxVowels
        
