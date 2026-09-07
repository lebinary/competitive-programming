# 322. Coin Change
# Difficulty: Medium
# Status: Accepted
# Runtime: 1256 ms (beats 7.1%)
# Memory: 45.6 MB (beats 19.4%)
# Submitted: 2024-10-19 10:13:06 UTC
# URL: https://leetcode.com/submissions/detail/1427182374/

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # Top-down DP
        memo = {} # { amount -> coinChange }

        # how many coins it takes to get from "amount" to "0" ?
        def dfs(curr_amount):
            if curr_amount == 0:
                return 0
            if curr_amount < 0:
                return float('inf')
            if curr_amount in memo:
                return memo[curr_amount]

            min_coins = float('inf')
            for coin in coins:
                coin_counts = dfs(curr_amount - coin)
                if coin_counts >= 0:
                    min_coins = min(min_coins, coin_counts + 1)

            memo[curr_amount] = min_coins
            return min_coins

        res = dfs(amount)
        return res if res != float('inf') else -1 
