# 300. Longest Increasing Subsequence
# Difficulty: Medium
# Status: Accepted
# Runtime: 1830 ms (beats 12.0%)
# Memory: 16.8 MB (beats 100.0%)
# Submitted: 2024-10-25 11:55:57 UTC
# URL: https://leetcode.com/submissions/detail/1433326576/

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        dp = [1] * len(nums)

        for i in range(len(nums)-1, -1, -1):
            for j in range(i+1, len(dp)):
                if nums[i] < nums[j]:
                    dp[i] = max(dp[i], 1 + dp[j])
        
        return max(dp)
