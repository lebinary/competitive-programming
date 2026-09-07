# 647. Palindromic Substrings
# Difficulty: Medium
# Status: Accepted
# Runtime: 116 ms (beats 98.4%)
# Memory: 13.5 MB (beats 15.2%)
# Submitted: 2022-03-03 10:52:27 UTC
# URL: https://leetcode.com/submissions/detail/652534863/

class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        pali_count = 0
        
        for i in range(len(s)):
            l, r = i, i
            
            #odd length
            while l >= 0 and r < len(s) and s[l] == s[r]:
                pali_count += 1
                
                l -= 1
                r += 1
            
            l, r = i, i+1
            
            #even length
            while l >= 0 and r < len(s) and s[l] == s[r]:
                pali_count += 1
                
                l -= 1
                r += 1
                
        return pali_count
        
