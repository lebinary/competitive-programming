# 416. Partition Equal Subset Sum
# Difficulty: Medium
# Status: Accepted
# Runtime: 1055 ms (beats 39.2%)
# Memory: 32.2 MB (beats 43.3%)
# Submitted: 2024-10-26 13:23:28 UTC
# URL: https://leetcode.com/submissions/detail/1434211300/

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        # bottom up, 2D array
        total_sum = sum(nums)
        if total_sum % 2:
            return False

        target = total_sum // 2
        n = len(nums)

        # dp[n][target] 
        dp = [[False] * (target + 1) for _ in range(n + 1)]
        dp[0][0] = True # can always reach target 0 from empty set {}

        for i in range(1, n + 1):
            curr_num = nums[i - 1]

            for j in range(target + 1):
                curr_target = j

                if curr_target < curr_num:
                    dp[i][j] = dp[i-1][j] # can reach curr_target excluding curr_num?
                else:
                    dp[i][j] = dp[i-1][j] or \
                                dp[i-1][j - curr_num]   # can reach curr_target including curr_num? 
                                                        #   .because if: curr_target - curr_num <=> valid_set,
                                                        #          then: valid_set + curr_sum <=> curr_target
        return dp[n][target]
