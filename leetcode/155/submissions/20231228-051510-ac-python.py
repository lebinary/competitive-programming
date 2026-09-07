# 155. Min Stack
# Difficulty: Medium
# Status: Accepted
# Runtime: 49 ms (beats 100.0%)
# Memory: 19.2 MB (beats 100.0%)
# Submitted: 2023-12-28 05:15:10 UTC
# URL: https://leetcode.com/submissions/detail/1130250647/


class MinStack(object):

    def __init__(self):
        self.head = None
        

    def push(self, val):
        """
        :type val: int
        :rtype: None
        """
        if self.head:
            self.head = Node(val, min(self.head.min, val), self.head)
        else:
            self.head = Node(val, val, None)
        

    def pop(self):
        """
        :rtype: None
        """
        self.head = self.head.next 
        

    def top(self):
        """
        :rtype: int
        """
        return self.head.val
        

    def getMin(self):
        """
        :rtype: int
        """
        return self.head.min


class Node(object):
    def __init__(self, val, minimum, nextNode):
        self.val = val
        self.min = minimum
        self.next = nextNode

# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
