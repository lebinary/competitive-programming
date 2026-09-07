# 300. Longest Increasing Subsequence
# Difficulty: Medium
# Status: Accepted
# Runtime: 4805 ms (beats 5.0%)
# Memory: 13.8 MB (beats 11.0%)
# Submitted: 2022-02-25 14:19:55 UTC
# URL: https://leetcode.com/submissions/detail/648690041/

class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0: return 0
        
        dp = [1] * len(nums)
        
        for i in range(len(nums)-1, -1, -1):
            for j in range(i+1, len(nums)):
                if nums[i] < nums[j]:
                    dp[i] = max(dp[i], 1 + dp[j])
        print(dp)
        return max(dp)
        
