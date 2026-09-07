# 309. Best Time to Buy and Sell Stock with Cooldown
# Difficulty: Medium
# Status: Accepted
# Runtime: 4 ms (beats 39.8%)
# Memory: 17.2 MB (beats 100.0%)
# Submitted: 2024-11-10 11:11:35 UTC
# URL: https://leetcode.com/submissions/detail/1448598113/

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        dp = [[0] * 2 for _ in range(n+1)]

        for i in range(n-1, -1, -1):
            for j in range(2):
                curr_price = prices[i]
                
                if j == 0: # buying at point i
                    # equals max of sell vs skip of previous results
                    skip = dp[i+1][0]
                    sell = dp[i+1][1] - curr_price
                    dp[i][j] = max(sell, skip)
                else: # selling at point i
                    # equals max of buy vs skip of previous results
                    # i+2 on buy to account for mandatory skip after sell
                    skip = dp[i+1][1]
                    buy = (dp[i+2][0] + curr_price) if i + 2 < n else curr_price
                    dp[i][j] = max(buy, skip)
        
        return dp[0][0]
