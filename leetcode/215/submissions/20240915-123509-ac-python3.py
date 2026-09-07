# 215. Kth Largest Element in an Array
# Difficulty: Medium
# Status: Accepted
# Runtime: 1239 ms (beats 5.0%)
# Memory: 29.9 MB (beats 94.3%)
# Submitted: 2024-09-15 12:35:09 UTC
# URL: https://leetcode.com/submissions/detail/1391004898/

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        if len(nums) == 1: return nums[0]

        # create a maxheap
        max_heap = MaxHeap(nums)

        # pop max heap k times
        res = None
        for _ in range(k):
            res = max_heap.pop()

        # return
        return res

class MaxHeap:
    def __init__(self, nums: List[int]) -> None:
        self.heap = []
        for num in nums:
            self.push(num)
    
    def size(self) -> int:
        return len(self.heap)
    
    def top(self) -> int:
        if not self.heap: return None
        
        return self.heap[0] 
    
    def swap(self, i: int, j: int) -> None:
        self.heap[i], self.heap[j] = self.heap[j], self.heap[i]
    
    def push(self, val: int) -> None:
        self.heap.append(val)
        self.heapify_up(len(self.heap) - 1)

    def pop(self) -> int:
        if not self.heap: return None

        res = self.heap[0]
        self.heap[0] = self.heap[len(self.heap) - 1]
        self.heap.pop()
        self.heapify_down(0)

        return res

    def heapify_up(self, idx: int) -> None:
        smallest = idx
        parent = (idx - 1) // 2

        if parent >= 0 and self.heap[parent] < self.heap[smallest]:
            smallest = parent

        # current idx is smallest, cannot bubble up
        if smallest == idx:
            return
        
        self.swap(idx, parent)
        self.heapify_up(parent)
    
    def heapify_down(self, idx: int) -> None:
        largest = idx
        left = 2*idx + 1
        right = 2*idx + 2

        if left < len(self.heap) and self.heap[left] > self.heap[largest]:
            largest = left
        if right < len(self.heap) and self.heap[right] > self.heap[largest]:
            largest = right

        # current idx is largest, cannot bubble down
        if largest == idx:
            return
        
        self.swap(idx, largest)
        self.heapify_down(largest)
