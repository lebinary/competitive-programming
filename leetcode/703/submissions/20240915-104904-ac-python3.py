# 703. Kth Largest Element in a Stream
# Difficulty: Easy
# Status: Accepted
# Runtime: 184 ms (beats 7.3%)
# Memory: 22.6 MB (beats 100.0%)
# Submitted: 2024-09-15 10:49:04 UTC
# URL: https://leetcode.com/submissions/detail/1390927752/

class KthLargest:
    def __init__(self, k: int, nums: List[int]):
        self.k = k
        self.min_heap = []
        for num in nums:
            self.add(num)    
    
    def add(self, val: int) -> int:
        # add to the heap
        self.min_heap.append(val)
        self.heapify_up()

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
        self.heapify_down()

        return smallest

    def swap(self, i: int, j: int) -> None:
        self.min_heap[i], self.min_heap[j] = self.min_heap[j], self.min_heap[i]

    def heapify_down(self) -> None:
        idx = 0
        left_child_idx = 2*idx + 1
        while left_child_idx < len(self.min_heap): # while there is a left child
            smaller_child_idx = left_child_idx # set to left child first

            right_child_idx = 2*idx + 2
            if right_child_idx < len(self.min_heap) and self.min_heap[right_child_idx] < self.min_heap[smaller_child_idx]: # there is a right child 
                smaller_child_idx = right_child_idx
            
            if self.min_heap[idx] < self.min_heap[smaller_child_idx]:
                break
            else:
                self.swap(idx, smaller_child_idx)
                idx = smaller_child_idx
                left_child_idx = 2*idx + 1
    
    def heapify_up(self) -> None:
        idx = len(self.min_heap) - 1
        parent_idx = (idx - 1) // 2

        # while there is parent and current < parent
        while parent_idx >= 0 and self.min_heap[idx] < self.min_heap[parent_idx]:
            self.swap(idx, parent_idx)
            idx = parent_idx
            parent_idx = (idx - 1) // 2
        


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)
