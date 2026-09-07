# 153. Find Minimum in Rotated Sorted Array
# Difficulty: Medium
# Status: Accepted
# Runtime: 38 ms (beats 0.9%)
# Memory: 13.8 MB (beats 35.9%)
# Submitted: 2022-02-13 07:52:05 UTC
# URL: https://leetcode.com/submissions/detail/640424617/

class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        time_rotated = 0
        for i in range(1, len(nums)):
            time_rotated += 1
            if nums[i] < nums[i-1]:
                return nums[i]
            
        return nums[0]           
        
