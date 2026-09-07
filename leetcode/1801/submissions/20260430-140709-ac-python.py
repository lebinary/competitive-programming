# 1801. Number of Orders in the Backlog
# Difficulty: Medium
# Status: Accepted
# Runtime: 732 ms (beats 18.8%)
# Memory: 55 MB (beats 33.8%)
# Submitted: 2026-04-30 14:07:10 UTC
# URL: https://leetcode.com/submissions/detail/1991861220/

"""
naive algorithm:
- for each order:
    if buy order:
        pop out any sell orders that match
        push the remaining buy orders
    if sell order:
        pop out any buy orders that match
        push the remaining sell orders
    
optimize solution (to avoid MLE)
- sell_map: {price => amount}
- buy_map: {price => amount}
- for each order:
    if buy order:
        while top of sell_backlog is amount = 0:
            clear the top

        if sell_price (top of heap) <= buy_price"
            if buy_amount >= sell_amount:
                sell_map[sell_price] = 0
                sell_backlog.pop
                buy_backlog << buy_price
                buy_map[buy_price] += diff
            else:
                sell_map[sell_price] -= buy_amount

    if sell order:
        while top of buy_backlog is amount = 0:
            clear the top 


        

"""

class Solution(object):
    def getNumberOfBacklogOrders(self, orders):
        """
        :type orders: List[List[int]]
        :rtype: int
        """
        sell_map, buy_map = defaultdict(int), defaultdict(int)
        sell_bl, buy_bl = [], []

        for i, (price, amount, order_type) in enumerate(orders):
            if order_type == 0:
                remaining = amount
                while sell_bl and remaining > 0 and sell_bl[0] <= price:
                    min_sell_price = sell_bl[0]

                    # stale record
                    if sell_map[min_sell_price] == 0:
                        heapq.heappop(sell_bl)
                        continue
                    
                    consume_amount = min(sell_map[min_sell_price], remaining)
                    sell_map[min_sell_price] = max(0, sell_map[min_sell_price] - consume_amount)
                    remaining -= consume_amount

                if remaining > 0:
                    heapq.heappush(buy_bl, -price)
                    buy_map[price] += remaining

            else:
                remaining = amount
                while buy_bl and remaining > 0 and -buy_bl[0] >= price:
                    max_buy_price = -buy_bl[0]

                    # stale record
                    if buy_map[max_buy_price] == 0:
                        heapq.heappop(buy_bl)
                        continue
                    consume_amount = min(buy_map[max_buy_price], remaining)
                    buy_map[max_buy_price] = max(0, buy_map[max_buy_price] - consume_amount)
                    remaining -= consume_amount
                
                if remaining > 0:
                    heapq.heappush(sell_bl, price)
                    sell_map[price] += remaining
        
        res = sum(sell_map.values()) + sum(buy_map.values())
        return res % (10**9 + 7)

        
