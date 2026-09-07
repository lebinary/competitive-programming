# 53. Maximum Subarray
# Difficulty: Medium
# Status: Accepted
# Runtime: 762 ms (beats 5.2%)
# Memory: 25.6 MB (beats 10.7%)
# Submitted: 2022-03-09 08:40:56 UTC
# URL: https://leetcode.com/submissions/detail/656442376/

class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        
        res = nums[0]
        curr_sum = 0
        
        for num in nums:
            curr_sum += num
            
            if curr_sum > res: res = curr_sum
            if curr_sum < 0: curr_sum = 0
            
        return res
            
            
            
        
