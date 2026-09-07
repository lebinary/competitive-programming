# 125. Valid Palindrome
# Difficulty: Easy
# Status: Accepted
# Runtime: 53 ms (beats 31.8%)
# Memory: 14 MB (beats 21.6%)
# Submitted: 2022-03-03 07:44:10 UTC
# URL: https://leetcode.com/submissions/detail/652462388/

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
                if not s[l].isalnum(): l += 1
                if not s[r].isalnum(): r -= 1
            else:
                l += 1
                r -= 1
        return True
