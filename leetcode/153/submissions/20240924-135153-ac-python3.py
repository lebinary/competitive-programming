# 153. Find Minimum in Rotated Sorted Array
# Difficulty: Medium
# Status: Accepted
# Runtime: 47 ms (beats 0.2%)
# Memory: 17 MB (beats 100.0%)
# Submitted: 2024-09-24 13:51:53 UTC
# URL: https://leetcode.com/submissions/detail/1400749658/

class Solution:
    def findMin(self, nums: List[int]) -> int:
        l = 0
        r = len(nums)

        # look for the pivot
        while l < r:
            m = l + (r-l) // 2

            # If middle element is greater than the next element,
            # we've found the pivot point
            if m < len(nums) - 1 and nums[m] > nums[m + 1]:
                return nums[m + 1]

            # If middle element is less than the previous element,
            # we've found the pivot point
            if m > 0 and nums[m] < nums[m - 1]:
                return nums[m]

            if nums[m] >= nums[0]:  # We are in the left sorted portion
                l = m + 1
            else:  # We are in the right sorted portion
                r = m

        # there is no pivot, return the first element
        return nums[0]
