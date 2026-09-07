# 20. Valid Parentheses
# Difficulty: Easy
# Status: Accepted
# Runtime: 35 ms (beats 6.0%)
# Memory: 13.5 MB (beats 6.3%)
# Submitted: 2023-12-28 04:42:26 UTC
# URL: https://leetcode.com/submissions/detail/1130231396/

class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []

        for i in range(len(s)):
            if s[i] == "(" or s[i] == "{" or s[i] == "[":
                stack.append(s[i])
            else:
                last = stack.pop() if stack else ""

                if not( (last == "(" and s[i] == ")") or (last == "{" and s[i] == "}") or (last == "[" and s[i] == "]") ):
                    return False
            
        return len(stack) == 0
        
