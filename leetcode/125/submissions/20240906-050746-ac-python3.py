# 125. Valid Palindrome
# Difficulty: Easy
# Status: Accepted
# Runtime: 42 ms (beats 5.6%)
# Memory: 17 MB (beats 100.0%)
# Submitted: 2024-09-06 05:07:46 UTC
# URL: https://leetcode.com/submissions/detail/1380703751/

class Solution:
    def isPalindrome(self, s: str) -> bool:
        l = 0
        r = len(s) - 1

        while l < r:
          if not s[l].isalnum():
            l += 1
          elif not s[r].isalnum():
            r -= 1
          elif s[l].lower() != s[r].lower():
            return False
          else:
            l += 1
            r -= 1
        
        return True
