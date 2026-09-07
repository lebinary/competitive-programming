# 312. Burst Balloons
# Difficulty: Hard
# Status: Accepted
# Runtime: 8557 ms (beats 5.0%)
# Memory: 33.2 MB (beats 38.8%)
# Submitted: 2024-11-20 11:20:32 UTC
# URL: https://leetcode.com/submissions/detail/1458171442/

class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nums = [1] + nums + [1]
        memo = {} # (l, r) -> max_coins

        def dfs(l, r):
            if l > r:
                return 0
            if (l, r) in memo:
                return memo[(l, r)]
            
            memo[(l, r)] = 0
            for i in range(l, r):
                coins = nums[l - 1] * nums[i] * nums[r]
                coins += dfs(l, i) + dfs(i+1, r)
                memo[(l, r)] = max(memo[(l, r)], coins)
            
            return memo[(l, r)]

        return dfs(1, len(nums) - 1)
