# 121. Best Time to Buy and Sell Stock
# Difficulty: Easy
# Status: Accepted
# Runtime: 829 ms (beats 5.2%)
# Memory: 22.6 MB (beats 13.8%)
# Submitted: 2021-10-11 13:09:20 UTC
# URL: https://leetcode.com/submissions/detail/569419187/

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        lowest = float('inf') 
        profit = 0
        for price in prices:
            if price < lowest: lowest = price
            elif price - lowest > profit: profit = price - lowest
        return profit
