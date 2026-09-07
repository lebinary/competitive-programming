# 704. Binary Search
# Difficulty: Easy
# Status: Accepted
# Runtime: 180 ms (beats 2.9%)
# Memory: 14.6 MB (beats 6.2%)
# Submitted: 2024-01-03 11:33:07 UTC
# URL: https://leetcode.com/submissions/detail/1135571447/

class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        l , r = 0, len(nums) - 1

        while l <= r:
            m = (l + r) // 2

            if nums[m] < target:
                l = m + 1
            elif nums[m] > target:
                r = m - 1
            else:
                return m
        
        return -1
