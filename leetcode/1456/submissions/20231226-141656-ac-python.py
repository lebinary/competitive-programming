# 1456. Maximum Number of Vowels in a Substring of Given Length
# Difficulty: Medium
# Status: Accepted
# Runtime: 196 ms (beats 12.2%)
# Memory: 17.3 MB (beats 7.1%)
# Submitted: 2023-12-26 14:16:56 UTC
# URL: https://leetcode.com/submissions/detail/1128912530/

class Solution(object):
    def maxVowels(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        res = 0
        vowels = ['a', 'e', 'i', 'o', 'u']

        l = 0
        cur_res = 0
        for r in range(len(s)):
            if s[r] in vowels:
                cur_res += 1
            
            if r - l + 1 > k:
                if s[l] in vowels:
                    cur_res -= 1
                l += 1

            res = max(res, cur_res)
        
        return res
