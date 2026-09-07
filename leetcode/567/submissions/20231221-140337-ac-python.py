# 567. Permutation in String
# Difficulty: Medium
# Status: Accepted
# Runtime: 35 ms (beats 37.3%)
# Memory: 13.8 MB (beats 18.4%)
# Submitted: 2023-12-21 14:03:37 UTC
# URL: https://leetcode.com/submissions/detail/1125119969/

class Solution(object):
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        if len(s1) > len(s2): return False

        count1 = [0] * 26
        count2 = [0] * 26

        l = 0
        r = 0
        while r < len(s1):
            count1[ord(s1[r]) - ord('a')] += 1
            count2[ord(s2[r]) - ord('a')] += 1
            r += 1

        # set r back to the end of s1
        r -= 1

        # sliding window
        while r < len(s2):
            if count1 == count2:
                return True
            
            r += 1
            if r != len(s2): count2[ord(s2[r]) - ord('a')] += 1
            
            count2[ord(s2[l]) - ord('a')] -= 1
            l += 1

        return False
            

        
