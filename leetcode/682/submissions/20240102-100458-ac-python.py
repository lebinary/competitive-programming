# 682. Baseball Game
# Difficulty: Easy
# Status: Accepted
# Runtime: 35 ms (beats 6.1%)
# Memory: 13.8 MB (beats 9.8%)
# Submitted: 2024-01-02 10:04:58 UTC
# URL: https://leetcode.com/submissions/detail/1134513933/

class Solution(object):
    def calPoints(self, operations):
        """
        :type operations: List[str]
        :rtype: int
        """
        stack = []

        for o in operations:
            if o == "+":
                stack.append(int(stack[-1] + stack[-2]))
            elif o == "D":
                stack.append(int(stack[-1] * 2))
            elif o == "C":
                stack.pop()
            else:
                stack.append(int(o))

        return sum(stack)
