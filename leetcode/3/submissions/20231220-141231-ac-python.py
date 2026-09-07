# 3. Longest Substring Without Repeating Characters
# Difficulty: Medium
# Status: Accepted
# Runtime: 48 ms (beats 63.0%)
# Memory: 14.4 MB (beats 38.7%)
# Submitted: 2023-12-20 14:12:31 UTC
# URL: https://leetcode.com/submissions/detail/1124290218/

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) < 2: return len(s)

        res = 0
        l = 0
        char_set = set()

        for r in range(len(s)):
            while s[r] in char_set:
                char_set.remove(s[l])
                l += 1

            char_set.add(s[r])
            res = max(res, len(char_set))
    
        return res
