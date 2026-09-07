# 22. Generate Parentheses
# Difficulty: Medium
# Status: Accepted
# Runtime: 39 ms (beats 5.3%)
# Memory: 16.9 MB (beats 100.0%)
# Submitted: 2024-09-07 05:30:08 UTC
# URL: https://leetcode.com/submissions/detail/1381727006/

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        stack = [("(", 1, 0)]
        
        while stack:
            curr, openN, closeN = stack.pop()
            if openN == closeN == n:
                res.append(curr)

            if openN < n:
                stack.append((curr+"(", openN+1, closeN))
            
            if closeN < openN:
                stack.append((curr+")", openN, closeN+1))
        
        return res
