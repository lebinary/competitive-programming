# 2349. Design a Number Container System
# Difficulty: Medium
# Status: Accepted
# Runtime: 155 ms (beats 58.7%)
# Memory: 77.1 MB (beats 39.6%)
# Submitted: 2026-06-13 12:44:14 UTC
# URL: https://leetcode.com/submissions/detail/2031776163/

"""
Key Obsevations:
- Index one-to-one mapping to Number
- Number one-to-many mapping to Index

Approach: Heap + Truth Dictionary
- DS: heap {number: index heap} and Dict {index: number}
- On find, if the index popped from heap is not in Truth Dict, ignore
"""

class NumberContainers:
    def __init__(self):
        self.heaps = defaultdict(list) # {number => index[]}
        self.truth = {} # {index => number}

    def change(self, index: int, number: int) -> None:
        heapq.heappush(self.heaps[number], index)
        self.truth[index] = number

    def find(self, number: int) -> int:
        while self.heaps[number] and self.truth.get(self.heaps[number][0], -1) != number:
            heapq.heappop(self.heaps[number])
        return self.heaps[number][0] if self.heaps[number] else -1
            


# Your NumberContainers object will be instantiated and called as such:
# obj = NumberContainers()
# obj.change(index,number)
# param_2 = obj.find(number)
