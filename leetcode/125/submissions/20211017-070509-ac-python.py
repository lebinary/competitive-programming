# 125. Valid Palindrome
# Difficulty: Easy
# Status: Accepted
# Runtime: 36 ms (beats 33.2%)
# Memory: 14.1 MB (beats 21.6%)
# Submitted: 2021-10-17 07:05:09 UTC
# URL: https://leetcode.com/submissions/detail/572536727/

class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        l = 0
        r = len(s)-1
        
        while l < r:
            if s[l].lower() != s[r].lower():
                if s[l].isalnum() and s[r].isalnum():
                    return False
                if not s[l].isalnum(): l += 1
                if not s[r].isalnum(): r -= 1
            else:
                l += 1
                r -= 1
        
        return True
            
                
            
        
