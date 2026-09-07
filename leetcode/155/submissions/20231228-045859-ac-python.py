# 155. Min Stack
# Difficulty: Medium
# Status: Accepted
# Runtime: 94 ms (beats 99.9%)
# Memory: 16.8 MB (beats 100.0%)
# Submitted: 2023-12-28 04:58:59 UTC
# URL: https://leetcode.com/submissions/detail/1130241026/

class MinStack(object):

    def __init__(self):
        self.stack = []
        self.min_stack = []
        

    def push(self, val):
        """
        :type val: int
        :rtype: None
        """
        self.stack.append(val)

        min_val = min(val , self.min_stack[-1] if self.min_stack else val)
        self.min_stack.append(min_val)
        

    def pop(self):
        """
        :rtype: None
        """
        self.stack.pop()
        self.min_stack.pop()
        

    def top(self):
        """
        :rtype: int
        """
        return self.stack[-1]
        

    def getMin(self):
        """
        :rtype: int
        """
        return self.min_stack[-1]
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
