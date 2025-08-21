#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

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
