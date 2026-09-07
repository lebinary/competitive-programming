# 152. Maximum Product Subarray
# Difficulty: Medium
# Status: Accepted
# Runtime: 15 ms (beats 7.2%)
# Memory: 20.3 MB (beats 8.6%)
# Submitted: 2024-10-20 13:17:54 UTC
# URL: https://leetcode.com/submissions/detail/1428358883/

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        # "Combo chain", will only increase if all positives
        # the only thing disrupt the chain are:
        #   . Negative number. Solution: store a min_so_far to be used later on
        #   . Zero. Solution: Reset the chain

        # max_so_far: accumulated "positive numbers" chain
        # min_so_far: properly handle negative number 
        dp = [[1, 1] for _ in range(len(nums) + 1)] # (max_so_far, min_so_far)[]
        res = nums[0]

        for i, num in enumerate(nums):
            max_so_far, min_so_far = dp[i]

            dp_idx = i + 1
            dp[dp_idx][0] = max(min_so_far * num, max_so_far * num, num)
            dp[dp_idx][1] = min(max_so_far * num, min_so_far * num, num)

            res = max(res, dp[dp_idx][0])
        print(dp)
        return res
