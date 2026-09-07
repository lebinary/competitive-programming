# 895. Maximum Frequency Stack
# Difficulty: Hard
# Status: Accepted
# Runtime: 240 ms (beats 7.2%)
# Memory: 21.1 MB (beats 85.5%)
# Submitted: 2026-04-30 17:23:33 UTC
# URL: https://leetcode.com/submissions/detail/1991994875/

class FreqStack(object):

    def __init__(self):
        self.frequency = defaultdict(int)
        self.timestamp = 0
        self.heap = []


    def push(self, val):
        """
        :type val: int
        :rtype: None
        """
        self.frequency[val] += 1
        self.timestamp += 1
        heapq.heappush(self.heap, (-self.frequency[val], -self.timestamp, val))

    def pop(self):
        """
        :rtype: int
        """
        while self.heap and -self.heap[0][0] != self.frequency[self.heap[0][2]]:
            heapq.heappop(self.heap)
            
        _, _, val = heapq.heappop(self.heap)
        self.frequency[val] -= 1
        return val
        


# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()
