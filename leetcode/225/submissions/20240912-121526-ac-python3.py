# 225. Implement Stack using Queues
# Difficulty: Easy
# Status: Accepted
# Runtime: 34 ms (beats 0.9%)
# Memory: 16.6 MB (beats 100.0%)
# Submitted: 2024-09-12 12:15:26 UTC
# URL: https://leetcode.com/submissions/detail/1387635968/

class MyStack:

    def __init__(self):
        self.q = deque()        

    def push(self, x: int) -> None:
        self.q.append(x)

    def pop(self) -> int:
        for i in range(len(self.q) - 1):
            el = self.q.popleft()
            self.q.append(el)
        
        return self.q.popleft()

    def top(self) -> int:
        return self.q[-1]

    def empty(self) -> bool:
        return len(self.q) == 0


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
