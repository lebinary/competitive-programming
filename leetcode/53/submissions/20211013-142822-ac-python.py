# 53. Maximum Subarray
# Difficulty: Medium
# Status: Accepted
# Runtime: 683 ms (beats 5.2%)
# Memory: 25.7 MB (beats 10.7%)
# Submitted: 2021-10-13 14:28:22 UTC
# URL: https://leetcode.com/submissions/detail/570599756/

class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 1: return nums[0]
        
        maxSoFar = nums[0]
        maxEndHere = 0
        
        for num in nums:
            maxEndHere += num
            if maxEndHere > maxSoFar: maxSoFar = maxEndHere
            if maxEndHere < 0: maxEndHere = 0
        return maxSoFar
