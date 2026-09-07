# 494. Target Sum
# Difficulty: Medium
# Status: Accepted
# Runtime: 172 ms (beats 30.3%)
# Memory: 38.1 MB (beats 40.9%)
# Submitted: 2024-11-12 10:11:11 UTC
# URL: https://leetcode.com/submissions/detail/1450472988/

class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        n = len(nums)
        memo = {} # (i, cumm) -> count

        def dfs(i, cumm):
            if i >= n:
                if cumm == target:
                    return 1
                else:
                    return 0
            if (i, cumm) in memo:
                return memo[(i, cumm)]
            
            add_dec = dfs(i+1, cumm + nums[i])
            sub_dec = dfs(i+1, cumm - nums[i])

            memo[(i, cumm)] = add_dec + sub_dec

            return memo[(i, cumm)]
        
        return dfs(0, 0)
