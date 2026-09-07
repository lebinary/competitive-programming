# 518. Coin Change II
# Difficulty: Medium
# Status: Accepted
# Runtime: 1083 ms (beats 17.8%)
# Memory: 272.5 MB (beats 15.9%)
# Submitted: 2024-11-11 10:16:30 UTC
# URL: https://leetcode.com/submissions/detail/1449461804/

class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        coins.sort() # need to sort in order to prevent duplicate

        res = 0
        memo = {} # (i, amount) => count

        def dfs(i, amount):
            if amount == 0:
                return 1
            if amount < 0 or i >= len(coins):
                return 0
            if (i, amount) in memo:
                return memo[(i, amount)]

            left_count = dfs(i, amount - coins[i])
            right_count = dfs(i+1, amount)

            memo[(i, amount)] = left_count + right_count
            return memo[(i, amount)]
        
        return dfs(0, amount)
