# 150. Evaluate Reverse Polish Notation
# Difficulty: Medium
# Status: Accepted
# Runtime: 63 ms (beats 6.1%)
# Memory: 17.1 MB (beats 100.0%)
# Submitted: 2024-09-06 15:12:19 UTC
# URL: https://leetcode.com/submissions/detail/1381182321/

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        operations = ["+", "-", "*", "/"]

        for t in tokens:
          if t not in operations:
            stack.append(int(t))
          else:
            operand1 = stack.pop()
            operand2 = stack.pop()

            if t == "+":
              stack.append(operand2 + operand1)
            elif t == "-":
              stack.append(operand2 - operand1)
            elif t == "*":
              stack.append(operand2 * operand1)
            else:
              stack.append(int(operand2 / operand1))
        
        return stack[0]
