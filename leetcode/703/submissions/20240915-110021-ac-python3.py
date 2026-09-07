# 703. Kth Largest Element in a Stream
# Difficulty: Easy
# Status: Accepted
# Runtime: 185 ms (beats 7.3%)
# Memory: 22.6 MB (beats 100.0%)
# Submitted: 2024-09-15 11:00:21 UTC
# URL: https://leetcode.com/submissions/detail/1390936324/

class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.k = k
        self.min_heap = []
        for num in nums:
            self.add(num)    
    
    def add(self, val: int) -> int:
        # add to the heap
        self.min_heap.append(val)
        self.heapify_up(len(self.min_heap) - 1)

        # poll until size heap == k
        while len(self.min_heap) > self.k:
            self.poll()

        # return the smallest element in heap
        return self.min_heap[0]
    
    def poll(self) -> None:
        if not self.min_heap: return None

        smallest = self.min_heap[0]
        self.min_heap[0] = self.min_heap[-1]
        self.min_heap.pop()
        self.heapify_down(0)

        return smallest

    def swap(self, i: int, j: int) -> None:
        self.min_heap[i], self.min_heap[j] = self.min_heap[j], self.min_heap[i]

    def heapify_down(self, idx: int) -> None:
        smallest = idx
        left = 2*idx + 1
        right = 2*idx + 2
        heap_size = len(self.min_heap)

        if left < heap_size and self.min_heap[left] < self.min_heap[smallest]:
            smallest = left
        if right < heap_size and self.min_heap[right] < self.min_heap[smallest]:
            smallest = right
        
        if smallest == idx: # base case: idx is smallest possible, cannot bubble down anymore
            return

        # else: continue bubble down
        self.swap(idx, smallest)
        self.heapify_down(smallest)
        
    
    def heapify_up(self, idx: int) -> None:
        largest = idx
        parent = (idx - 1) // 2

        if parent >= 0 and self.min_heap[parent] > self.min_heap[largest]:
            largest = parent
        
        if largest == idx: # base case: idx is largest possible, cannot bubble up anymore
            return
        
        # else: continue bubble up
        self.swap(idx, largest)
        self.heapify_up(largest)

