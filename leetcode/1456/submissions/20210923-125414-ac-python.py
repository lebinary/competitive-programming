# 1456. Maximum Number of Vowels in a Substring of Given Length
# Difficulty: Medium
# Status: Accepted
# Runtime: 284 ms (beats 5.1%)
# Memory: 17.3 MB (beats 7.1%)
# Submitted: 2021-09-23 12:54:14 UTC
# URL: https://leetcode.com/submissions/detail/559722366/

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
            print(s[i])
            if s[i] in "aeiou": vowels +=1
            if s[i-k] in "aeiou": vowels -=1
            maxVowels = max(maxVowels, vowels)
            
        return maxVowels
        
