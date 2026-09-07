# 5. Longest Palindromic Substring
# Difficulty: Medium
# Status: Accepted
# Runtime: 4116 ms (beats 13.3%)
# Memory: 13.4 MB (beats 5.0%)
# Submitted: 2022-03-03 10:33:58 UTC
# URL: https://leetcode.com/submissions/detail/652528693/

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
            while l >= 0 and r < len(s) and s[l] == s[r]:                
                
                if len(s[l : r+1]) > len(res):
                    res = s[l : r+1]
                
                l -= 1
                r += 1
            
            l, r = i, i+1
            #even length
            while l >= 0 and r < len(s) and s[l] == s[r]:                
                
                if len(s[l : r+1]) > len(res):
                    res = s[l : r+1]
                
                l -= 1
                r += 1
        
        return res    
                
                
