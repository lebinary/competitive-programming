# 3. Longest Substring Without Repeating Characters
# Difficulty: Medium
# Status: Accepted
# Runtime: 47 ms (beats 63.1%)
# Memory: 14.2 MB (beats 39.3%)
# Submitted: 2023-12-20 14:00:23 UTC
# URL: https://leetcode.com/submissions/detail/1124281963/

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) == 1 or len(s) == 0: return len(s)

        res = 0
        sub_str = ""

        for i in range(len(s)):
            if s[i] in sub_str:
                index = sub_str.index(s[i])
                sub_str = sub_str[index + 1:]

            sub_str += s[i]
            res = max(res, len(sub_str))
    
        return res
