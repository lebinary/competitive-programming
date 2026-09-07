# 33. Search in Rotated Sorted Array
# Difficulty: Medium
# Status: Accepted
# Runtime: 15 ms (beats 0.7%)
# Memory: 13.5 MB (beats 9.7%)
# Submitted: 2024-01-06 13:39:06 UTC
# URL: https://leetcode.com/submissions/detail/1138491023/

class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        l = 0
        r = len(nums) - 1

        while l <= r:
            m = (l + r) // 2

            if nums[m] == target:
                return m

            # Look to the right
            if nums[l] > nums[m]:
                if target > nums[r] or target < nums[m]:
                    r = m - 1
                else:
                    l = m + 1
            # Look to the left
            else:
                if target < nums[l] or target > nums[m]:
                    l = m + 1
                else:
                    r = m - 1
        
        return -1
