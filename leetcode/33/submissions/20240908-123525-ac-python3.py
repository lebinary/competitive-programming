# 33. Search in Rotated Sorted Array
# Difficulty: Medium
# Status: Accepted
# Runtime: 44 ms (beats 0.1%)
# Memory: 16.9 MB (beats 100.0%)
# Submitted: 2024-09-08 12:35:25 UTC
# URL: https://leetcode.com/submissions/detail/1383194806/

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l = 0
        r = len(nums) - 1

        while l <= r:
          m = l + (r - l) // 2

          if target == nums[m]:
            return m
            
          if nums[m] < nums[r]: # right side is sorted
            if nums[m] < target <= nums[r]: # if target is in sorted portion
              l = m + 1
            else:
              r = m -1
          else: # left side is sorted
            if nums[l] <= target < nums[m]:
              r = m - 1 
            else:
              l = m + 1

        return -1
