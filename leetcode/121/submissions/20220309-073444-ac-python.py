# 121. Best Time to Buy and Sell Stock
# Difficulty: Easy
# Status: Accepted
# Runtime: 1090 ms (beats 5.2%)
# Memory: 22.7 MB (beats 13.8%)
# Submitted: 2022-03-09 07:34:44 UTC
# URL: https://leetcode.com/submissions/detail/656412887/

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        l = 0
        r = 1
        res = 0
        
        while r < len(prices):
            if prices[l] < prices[r]:
                res = max(res, prices[r] - prices[l])
            else:
                l = r
            r += 1
        return res
                         
        
