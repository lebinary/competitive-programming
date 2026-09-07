# 153. Find Minimum in Rotated Sorted Array
# Difficulty: Medium
# Status: Accepted
# Runtime: 30 ms (beats 0.9%)
# Memory: 13.5 MB (beats 35.9%)
# Submitted: 2024-01-04 13:20:37 UTC
# URL: https://leetcode.com/submissions/detail/1136648240/

class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l, r = 0, len(nums) - 1
        res = float('inf')

        while l <= r:
            m = (l + r) // 2
            res = min(res, nums[m])

            if nums[m] > nums[r]:
                l = m + 1
            else:
                r = m - 1
        
        return res

        
