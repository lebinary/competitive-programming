# 150. Evaluate Reverse Polish Notation
# Difficulty: Medium
# Status: Accepted
# Runtime: 87 ms (beats 5.5%)
# Memory: 15.5 MB (beats 11.8%)
# Submitted: 2023-12-28 06:03:25 UTC
# URL: https://leetcode.com/submissions/detail/1130281527/

class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        stack = []

        for t in tokens:
            res = None
            if t == "+":
                num2 = stack.pop()
                num1 = stack.pop()
                res = num1 + num2
            elif t == "-":
                num2 = stack.pop()
                num1 = stack.pop()
                res = num1 - num2
            elif t == "*":
                num2 = stack.pop()
                num1 = stack.pop()
                res = num1 * num2
            elif t == "/":
                num2 = stack.pop()
                num1 = stack.pop()
                res = int(float(num1) / num2)
            else:
                res = int(t)
            
            stack.append(res)
        
        return stack.pop()
