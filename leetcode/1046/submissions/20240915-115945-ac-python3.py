# 1046. Last Stone Weight
# Difficulty: Easy
# Status: Accepted
# Runtime: 45 ms (beats 0.1%)
# Memory: 16.5 MB (beats 100.0%)
# Submitted: 2024-09-15 11:59:45 UTC
# URL: https://leetcode.com/submissions/detail/1390979497/

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        # max_heap
        max_heap = MaxHeap(stones) 

        # while max_heap size > 1
        # pop 2 tops out of the heap
        # return the result back onto the heap
        while max_heap.size() > 1:
            first = max_heap.poll()
            second = max_heap.poll()

            if first < second:
                max_heap.add(second - first)
            elif second < first:
                max_heap.add(first - second)

        # return 0 of weight of last stone
        res = max_heap.peek()
        return res if res else 0

class MaxHeap:
    def __init__(self, nums: List[int]) -> None:
        self.heap = []
        for num in nums:
            self.add(num)
    
    def peek(self) -> int:
        if not self.heap: return None
        return self.heap[0]

    def swap(self, i: int, j: int) -> None:
        self.heap[i], self.heap[j] = self.heap[j], self.heap[i]

    def add(self, val) -> int:
        self.heap.append(val)
        self.heapify_up(len(self.heap) - 1)
 
    def poll(self) -> int:
        if not self.heap: return None

        res = self.heap[0]
        self.heap[0] = self.heap[len(self.heap) - 1]
        self.heap.pop()
        self.heapify_down(0)

        return res

    def heapify_up(self, idx: int) -> None:
        smallest = idx
        parent = (idx - 1) // 2

        # check if parent smaller current idx
        if parent >= 0 and self.heap[parent] < self.heap[smallest]:
            smallest = parent

        # if no, done bubble up
        if smallest == idx:
            return

        # if yes, swap and continue
        self.swap(idx, parent)
        self.heapify_up(parent)


    def heapify_down(self, idx: int) -> int:
        largest = idx
        left = 2*idx + 1
        right = 2*idx + 2

        # check if any child larget than current idx
        if left < len(self.heap) and self.heap[left] > self.heap[largest]:
            largest = left
        if right < len(self.heap) and self.heap[right] > self.heap[largest]:
            largest = right
        
        # if no, done bubble down
        if largest == idx:
            return
        
        # if yes, swap and continue bubble down
        self.swap(idx, largest)
        self.heapify_down(largest)
    
    def size(self) -> int:
        return len(self.heap)
