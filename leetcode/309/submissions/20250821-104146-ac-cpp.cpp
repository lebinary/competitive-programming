/*
 * 309. Best Time to Buy and Sell Stock with Cooldown
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 15.5 MB (beats 72.5%)
 * Submitted: 2025-08-21 10:41:47 UTC
 * URL: https://leetcode.com/submissions/detail/1743088699/
 */


class Solution {
  public:
    vector<int> dp, dp1;
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        this->dp = vector<int>(n, -1);
        this->dp1 = vector<int>(n, -1);
        return buy(prices, 0);
    }

    int buy(vector<int> &prices, int i) {
        if (i >= prices.size()) return 0;
        if (dp[i] != -1) return dp[i];
        return dp[i] = max(buy(prices, i + 1), sell(prices, i + 1) - prices[i]);
    }

    int sell(vector<int> &prices, int i) {
        if (i >= prices.size()) return 0;
        if (dp1[i] != -1) return dp1[i];
        return dp1[i] = max(sell(prices, i + 1), buy(prices, i + 2) + prices[i]);
    }
};
