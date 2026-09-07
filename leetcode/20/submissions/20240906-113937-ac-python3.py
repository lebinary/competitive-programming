# 20. Valid Parentheses
# Difficulty: Easy
# Status: Accepted
# Runtime: 30 ms (beats 3.8%)
# Memory: 16.6 MB (beats 100.0%)
# Submitted: 2024-09-06 11:39:37 UTC
# URL: https://leetcode.com/submissions/detail/1381007886/

class Solution:
    def isValid(self, s: str) -> bool:
        stack = []

        for p in s:
          if p in "([{":
            stack.append(p)
          else:
            last = stack.pop() if len(stack) > 0 else None
            if p == ")" and last != "(":
              return False
            elif p == "]" and last != "[":
              return False
            elif p == "}" and last != "{":
              return False
        
        return len(stack) == 0
