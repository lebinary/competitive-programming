# 152. Maximum Product Subarray
# Difficulty: Medium
# Status: Accepted
# Runtime: 15 ms (beats 7.2%)
# Memory: 19.1 MB (beats 100.0%)
# Submitted: 2024-10-20 13:00:15 UTC
# URL: https://leetcode.com/submissions/detail/1428345690/

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        dp = [[1, 1] for _ in range(len(nums) + 1)] # (max, min)
        res = nums[0]

        for i, num in enumerate(nums):
            max_so_far, min_so_far = dp[i]

            dp_idx = i + 1
            dp[dp_idx][0] = max(min_so_far * num, max_so_far * num, num)
            dp[dp_idx][1] = min(max_so_far * num, min_so_far * num, num)

            res = max(res, dp[dp_idx][0])

        return res
