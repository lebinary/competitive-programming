# 494. Target Sum
# Difficulty: Medium
# Status: Accepted
# Runtime: 178 ms (beats 25.7%)
# Memory: 36.9 MB (beats 40.9%)
# Submitted: 2024-11-12 10:27:20 UTC
# URL: https://leetcode.com/submissions/detail/1450483927/

class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        if not -sum(nums) <= target <= sum(nums):
            return 0

        n = len(nums)
        memo = {} # (i, cumm) -> count

        def dfs(i, cumm):
            if i >= n:
                if cumm == 0:
                    return 1
                else:
                    return 0
            if (i, cumm) in memo:
                return memo[(i, cumm)]
            
            add_dec = dfs(i+1, cumm + nums[i])
            sub_dec = dfs(i+1, cumm - nums[i])

            memo[(i, cumm)] = add_dec + sub_dec

            return memo[(i, cumm)]
        
        return dfs(0, target)
