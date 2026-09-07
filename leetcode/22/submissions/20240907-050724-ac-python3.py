# 22. Generate Parentheses
# Difficulty: Medium
# Status: Accepted
# Runtime: 39 ms (beats 5.3%)
# Memory: 16.9 MB (beats 100.0%)
# Submitted: 2024-09-07 05:07:24 UTC
# URL: https://leetcode.com/submissions/detail/1381710286/

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        stack = []
        res = []

        def back_track(open_n, close_n):
          if open_n == close_n == n:
            res.append("".join(stack))
            return
          
          if open_n < n:
            stack.append("(")
            back_track(open_n + 1, close_n)
            stack.pop()
          
          if close_n < open_n:
            stack.append(")")
            back_track(open_n, close_n + 1)
            stack.pop()
        
        back_track(0, 0)

        return res
