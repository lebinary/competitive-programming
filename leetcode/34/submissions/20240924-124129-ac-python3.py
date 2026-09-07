# 34. Find First and Last Position of Element in Sorted Array
# Difficulty: Medium
# Status: Accepted
# Runtime: 77 ms (beats 0.3%)
# Memory: 17.9 MB (beats 100.0%)
# Submitted: 2024-09-24 12:41:29 UTC
# URL: https://leetcode.com/submissions/detail/1400684482/

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if not nums: return [-1, -1]

        # leftmost binary search
        l = 0
        r = len(nums)

        while l < r:
            m = l + (r - l) // 2

            if nums[m] < target:
                l = m + 1
            else:
                r = m
        
        leftmost = l if l < len(nums) and nums[l] == target else -1
            
        # rightmost binary search
        l = 0
        r = len(nums)

        while l < r:
            m = l + (r - l) // 2

            if nums[m] > target:
                r = m
            else:
                l = m + 1

        rightmost = l-1 if l-1 < len(nums) and nums[l-1] == target else -1
        
        return [leftmost, rightmost]
