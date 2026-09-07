# 20. Valid Parentheses
# Difficulty: Easy
# Status: Accepted
# Runtime: 30 ms (beats 6.0%)
# Memory: 13.6 MB (beats 6.3%)
# Submitted: 2021-10-19 14:49:35 UTC
# URL: https://leetcode.com/submissions/detail/573791070/

class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        for char in s:
            if char == "(":
                stack.append(")")
            elif char == "{":
                stack.append("}")
            elif char == "[":
                stack.append("]")
            else:
                if len(stack) > 0:
                    latest = stack.pop()
                    if latest != char: return False
                else: return False
            
        
        if len(stack) > 0: return False
        return True
                
            
