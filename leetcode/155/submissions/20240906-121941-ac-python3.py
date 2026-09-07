# 155. Min Stack
# Difficulty: Medium
# Status: Accepted
# Runtime: 62 ms (beats 97.8%)
# Memory: 20.8 MB (beats 100.0%)
# Submitted: 2024-09-06 12:19:41 UTC
# URL: https://leetcode.com/submissions/detail/1381035510/

class MinStack:

    def __init__(self):
        self.min_stack = []

    def push(self, val: int) -> None:
        if len(self.min_stack) == 0:
            self.min_stack.append((val, val))
        else:
            _, min_val = self.min_stack[-1]
            self.min_stack.append((val, min(val, min_val)))


    def pop(self) -> None:
        val, _ = self.min_stack.pop()
        return val

    def top(self) -> int:
        if len(self.min_stack) == 0:
            return None

        val, _ = self.min_stack[-1]
        return val

    def getMin(self) -> int:
        if len(self.min_stack) == 0:
            return None

        _, min_val = self.min_stack[-1]
        return min_val
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
