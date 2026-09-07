# 494. Target Sum
# Difficulty: Medium
# Status: Accepted
# Runtime: 180 ms (beats 22.3%)
# Memory: 37.6 MB (beats 40.9%)
# Submitted: 2024-11-12 10:20:06 UTC
# URL: https://leetcode.com/submissions/detail/1450479012/

class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
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
