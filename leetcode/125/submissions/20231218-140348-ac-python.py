# 125. Valid Palindrome
# Difficulty: Easy
# Status: Accepted
# Runtime: 25 ms (beats 35.2%)
# Memory: 14 MB (beats 21.6%)
# Submitted: 2023-12-18 14:03:48 UTC
# URL: https://leetcode.com/submissions/detail/1122628069/

class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        l = 0
        r = len(s) - 1

        while l < r:
            if s[l].lower() != s[r].lower():
                if s[l].isalnum() and s[r].isalnum():
                    return False
                if not s[l].isalnum():
                    l += 1
                if not s[r].isalnum():
                    r -= 1
            else:
                l += 1
                r -= 1
            
        return True
        
        

        
        
