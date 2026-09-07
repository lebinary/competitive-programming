# 309. Best Time to Buy and Sell Stock with Cooldown
# Difficulty: Medium
# Status: Accepted
# Runtime: 10 ms (beats 8.4%)
# Memory: 18.1 MB (beats 100.0%)
# Submitted: 2024-11-10 10:24:18 UTC
# URL: https://leetcode.com/submissions/detail/1448568449/

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        memo = {} # (i, buying) -> max_profit_at_i

        def dfs(i, buying):
            if i >= len(prices):
                return 0
            if (i, buying) in memo:
                return memo[(i, buying)]

            if buying:
                # Can either buy at this position and look to sell later
                # OR skip this position (cooldown) and look to buy later
                buy = dfs(i+1, not buying) - prices[i]
                skip = dfs(i+1, buying)
                memo[(i, buying)] = max(buy, skip)
                
            else:
                # Can either sell at this position then must cooldown
                # OR skip this position and continue holding to sell later
                sell = dfs(i+2, not buying) + prices[i]  # +2 for cooldown
                skip = dfs(i+1, buying)
                memo[(i, buying)] = max(sell, skip)
            
            return memo[(i, buying)]

        return dfs(0, True)
