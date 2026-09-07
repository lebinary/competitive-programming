# 121. Best Time to Buy and Sell Stock
# Difficulty: Easy
# Status: Accepted
# Runtime: 825 ms (beats 5.2%)
# Memory: 22.5 MB (beats 13.8%)
# Submitted: 2023-12-20 13:08:51 UTC
# URL: https://leetcode.com/submissions/detail/1124246654/

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        max_profit = 0

        lowest = prices[0]
        for price in prices:
            if price < lowest:
                lowest = price
            max_profit = max(max_profit, price - lowest)
        
        return max_profit
        
