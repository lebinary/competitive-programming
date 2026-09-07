# 703. Kth Largest Element in a Stream
# Difficulty: Easy
# Status: Accepted
# Runtime: 143 ms (beats 7.3%)
# Memory: 23 MB (beats 100.0%)
# Submitted: 2024-09-15 11:20:45 UTC
# URL: https://leetcode.com/submissions/detail/1390951378/

class KthLargest:
    # Binary search approach
    def __init__(self, k: int, nums: List[int]):
        self.k = k
        self.nums = sorted(nums)
    
    def add(self, val: int) -> int:
        # leftmost binary search to find the index
        l = 0
        r = len(self.nums)

        while l < r:
            m = l + (r - l) // 2

            if self.nums[m] < val:
                l = m + 1
            else:
                r = m
        
        # add val in index
        self.nums.insert(l, val)

        # return len(nums) - k
        return self.nums[-self.k]
