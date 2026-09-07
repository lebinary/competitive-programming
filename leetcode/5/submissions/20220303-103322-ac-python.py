# 5. Longest Palindromic Substring
# Difficulty: Medium
# Status: Accepted
# Runtime: 5174 ms (beats 11.4%)
# Memory: 13.6 MB (beats 5.0%)
# Submitted: 2022-03-03 10:33:22 UTC
# URL: https://leetcode.com/submissions/detail/652528463/

class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if len(s) == 0: return ""
        
        res = ""
        
        
        for i in range(len(s)):
            l, r = i, i

            #odd length
            while l >= 0 and r < len(s) and s[l].lower() == s[r].lower():                
                
                if len(s[l : r+1]) > len(res):
                    res = s[l : r+1]
                
                l -= 1
                r += 1
            
            l, r = i, i+1
            #even length
            while l >= 0 and r < len(s) and s[l].lower() == s[r].lower():                
                
                if len(s[l : r+1]) > len(res):
                    res = s[l : r+1]
                
                l -= 1
                r += 1
        
        return res    
                
                
