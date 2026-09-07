# 312. Burst Balloons
# Difficulty: Hard
# Status: Accepted
# Runtime: 8162 ms (beats 5.0%)
# Memory: 33.6 MB (beats 38.8%)
# Submitted: 2024-12-29 12:18:39 UTC
# URL: https://leetcode.com/submissions/detail/1491522113/

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
            for k in range(l, r):
                coins = nums[l - 1] * nums[k] * nums[r]
                coins += dfs(l, k) + dfs(k+1, r)
                res = max(res, coins)
            
            memo[(l, r)] = res
            return memo[(l, r)]

        return dfs(1, len(nums) - 1)
