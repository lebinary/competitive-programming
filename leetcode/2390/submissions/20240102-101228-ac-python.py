# 2390. Removing Stars From a String
# Difficulty: Medium
# Status: Accepted
# Runtime: 481 ms (beats 13.6%)
# Memory: 16.5 MB (beats 15.2%)
# Submitted: 2024-01-02 10:12:28 UTC
# URL: https://leetcode.com/submissions/detail/1134518764/

class Solution(object):
    def removeStars(self, s):
        """
        :type s: str
        :rtype: str
        """
        stack = []

        for c in s:
            if c == "*":
                stack.pop()
            else:
                stack.append(c)

        return "".join(stack)
