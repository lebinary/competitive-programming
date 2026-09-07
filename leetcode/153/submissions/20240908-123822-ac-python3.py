# 153. Find Minimum in Rotated Sorted Array
# Difficulty: Medium
# Status: Accepted
# Runtime: 48 ms (beats 0.2%)
# Memory: 16.7 MB (beats 100.0%)
# Submitted: 2024-09-08 12:38:22 UTC
# URL: https://leetcode.com/submissions/detail/1383197026/

class Solution:
    def findMin(self, nums: List[int]) -> int:
        l = 0
        r = len(nums) - 1
        res = float("inf")

        # key point is to look for the exact part of rotation
        while l <= r:
            m = l + (r-l) // 2
            res = min(res, nums[m])

            if nums[m] < nums[r]: # right side is sorted
                r = m - 1
            else:
                l = m + 1
        
        return min(res, nums[r])
