# 33. Search in Rotated Sorted Array
# Difficulty: Medium
# Status: Accepted
# Runtime: 50 ms (beats 0.1%)
# Memory: 16.7 MB (beats 100.0%)
# Submitted: 2024-09-13 04:15:25 UTC
# URL: https://leetcode.com/submissions/detail/1388362731/

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l = 0
        r = len(nums) - 1

        while l <= r:
            m = l + (r - l) // 2

            # we are in left portion but target in right portion
            if nums[m] >= nums[0] and target < nums[0]:
                l = m + 1
            # we are in right portion but target in left portion
            elif nums[m] < nums[0] and target >= nums[0]:
                r = m - 1
            
            # else do normal binary search
            elif nums[m] < target:
                l = m + 1
            elif nums[m] > target:
                r = m - 1
            else:
                return m
        
        return -1
