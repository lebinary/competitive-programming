# 295. Find Median from Data Stream
# Difficulty: Hard
# Status: Accepted
# Runtime: 1148 ms (beats 9.8%)
# Memory: 35.4 MB (beats 92.7%)
# Submitted: 2026-04-29 10:44:12 UTC
# URL: https://leetcode.com/submissions/detail/1990952668/

class MedianFinder(object):

    def __init__(self):
        self.left = []
        self.right = []
        self.n = 0

    def addNum(self, num):
        """
        :type num: int
        :rtype: None
        """
        self.n += 1
        heapq.heappush(self.left, -num)
        left_top = heapq.heappop(self.left)
        heapq.heappush(self.right, left_top * -1)

        if len(self.right) > len(self.left):
            right_top = heapq.heappop(self.right)
            heapq.heappush(self.left, right_top * -1)

    def findMedian(self):
        """
        :rtype: float
        """
        if self.n % 2 == 0:
            left_top = self.left[0]
            left_top *= -1
            right_top = self.right[0]
            return (left_top + right_top) / 2.0
        else:
            left_top = self.left[0]
            left_top *= -1
            return left_top
        


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
