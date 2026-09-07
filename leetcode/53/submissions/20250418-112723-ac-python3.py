# 53. Maximum Subarray
# Difficulty: Medium
# Status: Accepted
# Runtime: 87 ms (beats 5.1%)
# Memory: 32.8 MB (beats 6.6%)
# Submitted: 2025-04-18 11:27:23 UTC
# URL: https://leetcode.com/submissions/detail/1610443825/

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        res = nums[0]
        curr_max = 0

        for num in nums:
            curr_max = max(curr_max, 0) + num
            res = max(res, curr_max)
        
        return res
