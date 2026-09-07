# 973. K Closest Points to Origin
# Difficulty: Medium
# Status: Accepted
# Runtime: 1340 ms (beats 5.0%)
# Memory: 23.2 MB (beats 99.9%)
# Submitted: 2024-09-16 16:03:45 UTC
# URL: https://leetcode.com/submissions/detail/1392269190/

import math
import copy

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        # min heap problem
        # turn points into minheap, where sorted by the euclidean length to origin
        # while k > 0: pop off the heap
        min_heap = MinHeap(points)
        res = []
        for _ in range(k):
            curr_min = min_heap.pop()
            res.append(curr_min)

        return res 
    
class MinHeap:
    def __init__(self, points: List[List[int]]):
        self.heap = []
        for point in points:
            self.push(point)

    def distance(self, point: List[int]) -> float:
        return math.sqrt(point[0]**2 + point[1]**2)
    
    def size(self) -> int:
        return len(self.heap)
    
    def swap(self, i: int, j: int) -> None:
        self.heap[i], self.heap[j] = self.heap[j], self.heap[i]

    def push(self, point: List[int]) -> None:
        self.heap.append(point)
        self.heapify_up(self.size() - 1)

    def pop(self) -> List[int]:
        if not self.heap: return None

        res = copy.deepcopy(self.heap[0])
        self.heap[0] = self.heap[-1]
        self.heap.pop()
        self.heapify_down(0)

        return res
    
    def heapify_up(self, idx: int) -> None:
        largest = idx
        parent = (idx - 1) // 2

        if parent >= 0 and self.distance(self.heap[parent]) > self.distance(self.heap[largest]):
            largest = parent
        
        # nothing larger than idx above, cannot heapify up
        if largest == idx:
            return
        
        self.swap(idx, parent)
        self.heapify_up(parent)
    
    def heapify_down(self, idx: int) -> None:
        smallest = idx
        left = (2 * idx) + 1
        right = (2 * idx) + 2

        if left < self.size() and self.distance(self.heap[left]) < self.distance(self.heap[smallest]):
            smallest = left
        if right < self.size() and self.distance(self.heap[right]) < self.distance(self.heap[smallest]):
            smallest = right
        
        # nothing smaller than idx below, cannot heapify down
        if smallest == idx:
            return
        
        self.swap(idx, smallest)
        self.heapify_down(smallest)
