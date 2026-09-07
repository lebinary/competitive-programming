# 312. Burst Balloons
# Difficulty: Hard
# Status: Accepted
# Runtime: 8095 ms (beats 5.9%)
# Memory: 34.1 MB (beats 38.8%)
# Submitted: 2024-12-29 12:17:22 UTC
# URL: https://leetcode.com/submissions/detail/1491521328/

class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nums = [1] + nums + [1]
        memo = {} # (l, r) -> max_coins

        def dfs(l, r):
            if l > r:
                return 0
            if (l, r) in memo:
                return memo[(l, r)]
            
            res = 0
            for i in range(l, r):
                coins = nums[l - 1] * nums[i] * nums[r]
                coins += dfs(l, i) + dfs(i+1, r)
                res = max(res, coins)
            
            memo[(l, r)] = res
            return memo[(l, r)]

        return dfs(1, len(nums) - 1)
