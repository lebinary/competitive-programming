# 322. Coin Change
# Difficulty: Medium
# Status: Accepted
# Runtime: 829 ms (beats 24.4%)
# Memory: 17.1 MB (beats 100.0%)
# Submitted: 2024-10-19 10:37:02 UTC
# URL: https://leetcode.com/submissions/detail/1427198557/

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # Bottom up DP
        # DP = { amount -> min coins to reach zero } 

        dp = [float('inf')] * (amount + 1)
        dp[0] = 0
        
        for amount in range(1, amount + 1):
            for coin in coins:
                if amount - coin >= 0:
                    dp[amount] = min(dp[amount], 1 + dp[amount - coin])
        
        return dp[amount] if dp[amount] != float('inf') else -1
