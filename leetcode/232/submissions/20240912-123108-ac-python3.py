# 232. Implement Queue using Stacks
# Difficulty: Easy
# Status: Accepted
# Runtime: 26 ms (beats 0.0%)
# Memory: 16.6 MB (beats 100.0%)
# Submitted: 2024-09-12 12:31:08 UTC
# URL: https://leetcode.com/submissions/detail/1387647315/

class MyQueue:

    def __init__(self):
        self.push_stack = []
        self.pop_stack = []

    def push(self, x: int) -> None:
        self.push_stack.append(x)

    def pop(self) -> int:
        if self.pop_stack:
            return self.pop_stack.pop()
        
        while self.push_stack:
            self.pop_stack.append(self.push_stack.pop())
        
        return self.pop_stack.pop()

    def peek(self) -> int:
        if self.pop_stack:
            return self.pop_stack[-1]
        
        while self.push_stack:
            self.pop_stack.append(self.push_stack.pop())
        
        return self.pop_stack[-1]

    def empty(self) -> bool:
        return len(self.push_stack) == 0 and len(self.pop_stack) == 0 

# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
