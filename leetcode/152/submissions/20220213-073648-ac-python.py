# 152. Maximum Product Subarray
# Difficulty: Medium
# Status: Accepted
# Runtime: 83 ms (beats 5.5%)
# Memory: 16.6 MB (beats 7.8%)
# Submitted: 2022-02-13 07:36:48 UTC
# URL: https://leetcode.com/submissions/detail/640417049/

class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0: return 0
        
        dp = [None] * (len(nums)+1)
        
        dp[0] = [1,1]
        
        res = max(nums)
        
        for i in range(0, len(nums)):
            curr_max = nums[i] * dp[i][0]
            curr_min = nums[i] * dp[i][1]
            
            dp[i+1] = [None, None]
            dp[i+1][0] = max(curr_max, curr_min, nums[i])
            dp[i+1][1] = min(curr_max, curr_min, nums[i])
            
            res = max(curr_max, curr_min, res)
            
        return res
