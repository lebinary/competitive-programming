# 295. Find Median from Data Stream
# Difficulty: Hard
# Status: Accepted
# Runtime: 194 ms (beats 43.9%)
# Memory: 42.9 MB (beats 17.2%)
# Submitted: 2026-06-13 11:46:49 UTC
# URL: https://leetcode.com/submissions/detail/2031730831/

class MedianFinder:
    def __init__(self):
        self.leftHeap = [] # maxheap
        self.rightHeap = [] # minheap
        self.size = 0       

    def addNum(self, num: int) -> None:
        heapq.heappush(self.leftHeap, -num)
        topLeft = heapq.heappop(self.leftHeap)
        heapq.heappush(self.rightHeap, -topLeft)

        if len(self.rightHeap) > len(self.leftHeap):
            topRight = heapq.heappop(self.rightHeap)
            heapq.heappush(self.leftHeap, -topRight)

        self.size += 1

    def findMedian(self) -> float:
        topLeft = self.leftHeap[0]

        if self.size & 1:
            return -topLeft
        
        topRight = self.rightHeap[0]
        return (-topLeft + topRight) / 2
        


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
