# 704. Binary Search
# Difficulty: Easy
# Status: Accepted
# Runtime: 190 ms (beats 1.8%)
# Memory: 18.2 MB (beats 100.0%)
# Submitted: 2024-09-15 11:24:48 UTC
# URL: https://leetcode.com/submissions/detail/1390954434/

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # leftmost binary search
        l = 0
        r = len(nums)

        while l < r:
            m = l + (r - l) // 2
            
            if nums[m] == target:
                return m
            elif nums[m] < target:
                l = m + 1
            else:
                r = m

        return -1
