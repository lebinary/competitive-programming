# 75. Sort Colors
# Difficulty: Medium
# Status: Accepted
# Runtime: 39 ms (beats 2.2%)
# Memory: 16.5 MB (beats 100.0%)
# Submitted: 2024-09-18 13:39:55 UTC
# URL: https://leetcode.com/submissions/detail/1394388977/

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        l, m, r = 0, 0, len(nums) - 1

        while m <= r:
            if nums[m] == 0:
                nums[l], nums[m] = nums[m], nums[l]
                l += 1
                m += 1
            elif nums[m] == 1:
                m += 1
            else: # nums[m] == 2
                nums[r], nums[m] = nums[m], nums[r]
                r -= 1
