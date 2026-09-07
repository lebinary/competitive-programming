# 20. Valid Parentheses
# Difficulty: Easy
# Status: Accepted
# Runtime: 22 ms (beats 6.0%)
# Memory: 13.5 MB (beats 6.3%)
# Submitted: 2022-03-03 07:17:18 UTC
# URL: https://leetcode.com/submissions/detail/652448637/

class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if len(s) < 2: return False
        
        stack = []
        for c in s:
            if c == '{':
                stack.append("}")
            elif c == '(':
                stack.append(")")
            elif c == '[':
                stack.append("]")
            else:
                if len(stack) > 0:
                    latest_c = stack.pop()
                    if latest_c != c: return False
                else:
                    return False
                

        if len(stack) > 0: return False
        
        return True
                
