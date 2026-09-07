/*
 * 123. Best Time to Buy and Sell Stock III
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 283 ms (beats 53.3%)
 * Memory: 186.3 MB (beats 53.0%)
 * Submitted: 2026-03-23 12:39:30 UTC
 * URL: https://leetcode.com/submissions/detail/1956684327/
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dpBuy(n, vector<int>(2, -1));
        vector<vector<int>> dpNoBuy(n, vector<int>(2, -1));

        return buy(prices, dpBuy, dpNoBuy, n, 0, 0);
    }

    int buy(auto& prices, auto& dpBuy, auto& dpNoBuy, int n, int i, int trades) {
        if(i >= n || trades >= 2) return 0;
        if(dpBuy[i][trades] != -1) return dpBuy[i][trades];
        
        int profit = 0;
        profit = max(profit, -prices[i] + nobuy(prices, dpBuy, dpNoBuy, n, i + 1, trades));
        profit = max(profit, buy(prices, dpBuy, dpNoBuy, n, i + 1, trades));
        return dpBuy[i][trades] = profit;
    }

    int nobuy(auto& prices, auto& dpBuy, auto& dpNoBuy, int n, int i, int trades) {
        if(i >= n) return 0;
        if(dpNoBuy[i][trades] != -1) return dpNoBuy[i][trades];

        int profit = 0;
        profit = max(profit, prices[i] + buy(prices, dpBuy, dpNoBuy, n, i + 1, trades + 1));
        profit = max(profit, nobuy(prices, dpBuy, dpNoBuy, n, i + 1, trades));
        return dpNoBuy[i][trades] = profit;
    }
};

/**
What state? How many?
- current day: n
- current position: 2 (hold, not hold)
=> O(d * 2) = 10^5 < 10^7


**/
