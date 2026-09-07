# 22. Generate Parentheses
# Difficulty: Medium
# Status: Accepted
# Runtime: 33 ms (beats 4.8%)
# Memory: 13.9 MB (beats 19.4%)
# Submitted: 2023-12-30 03:53:57 UTC
# URL: https://leetcode.com/submissions/detail/1131881057/

class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        res = []
        def backtrack(l, r, s):
            if len(s) / 2 == n:
                res.append(s)
                return

            if l < n:
                s += "("
                backtrack(l + 1, r, s)
                s = s[:-1]
            
            if r < l:
                s += ")"
                backtrack(l, r + 1, s)
                s = s[:-1]

        backtrack(0, 0, "")

        return res
