# 2349. Design a Number Container System
# Difficulty: Medium
# Status: Accepted
# Runtime: 254 ms (beats 77.8%)
# Memory: 69.1 MB (beats 88.9%)
# Submitted: 2026-04-29 11:11:33 UTC
# URL: https://leetcode.com/submissions/detail/1990967331/

"""
sot = {
    1: 10
    2: 10
    3: 10
    5: 10
}

heap[10] = [1,2,3,5]

find(10) => return 1 (because it maps correctly with SOT)

change(1, 20):
sot = {
    1: 20
    2: 10
    3: 10
    5: 10
}
heap[10] = [1,2,3,5]
heap[20] = [1]

find(10) => clean the stale records if any on top, which includes index "1" (bc not mapping to SOT)
=> return 2

find(20) => return 1
"""

class NumberContainers(object):

    def __init__(self):
        self.sot = defaultdict(int)
        self.heap = defaultdict(list)

    def change(self, index, number):
        """
        :type index: int
        :type number: int
        :rtype: None
        """
        self.sot[index] = number
        heapq.heappush(self.heap[number], index)


    def find(self, number):
        """
        :type number: int
        :rtype: int
        """
        # clean stale records
        while self.heap[number] and self.sot[self.heap[number][0]] != number:
            heapq.heappop(self.heap[number])
        
        if not self.heap[number]:
            return -1
        
        return self.heap[number][0]


# Your NumberContainers object will be instantiated and called as such:
# obj = NumberContainers()
# obj.change(index,number)
# param_2 = obj.find(number)
