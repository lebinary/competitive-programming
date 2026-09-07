# 153. Find Minimum in Rotated Sorted Array
# Difficulty: Medium
# Status: Accepted
# Runtime: 46 ms (beats 0.2%)
# Memory: 16.7 MB (beats 100.0%)
# Submitted: 2024-09-08 11:48:07 UTC
# URL: https://leetcode.com/submissions/detail/1383159120/

class Solution:
    def findMin(self, nums: List[int]) -> int:
        l = 0
        r = len(nums) - 1
        res = float("inf")
        
        while l <= r:
            m = l + (r-l) // 2
            res = min(res, nums[m])

            if nums[m] > nums[r]:
                l = m + 1
            else:
                r = m - 1
        
        return min(res, nums[l])
