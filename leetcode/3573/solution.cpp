#include <algorithm>
#include <cctype>
#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
    vector<vector<long long>> dpFree, dpBuy, dpSell;
    vector<int> prices;
    int n;
    int k;

  public:
    long long maximumProfit(vector<int> &prices, int k) {
        this->prices = prices;
        this->n = prices.size();
        this->k = k;
        this->dpFree.assign(n + 1, vector<long long>(k + 1, -1));
        this->dpBuy.assign(n + 1, vector<long long>(k + 1, -1));
        this->dpSell.assign(n + 1, vector<long long>(k + 1, -1));

        return free(0, k);
    };

    long long free(int i, int k) {
        if (i >= n || k <= 0) return 0;
        if (dpFree[i][k] != -1) return dpFree[i][k];

        long long profit = 0;
        profit = max(profit, free(i + 1, k));             // nothing
        profit = max(profit, buy(i + 1, k) - prices[i]);  // long
        profit = max(profit, sell(i + 1, k) + prices[i]); // short

        return dpFree[i][k] = profit;
    }

    long long buy(int i, int k) {
        if (i >= n || k <= 0) return LLONG_MIN / 2;
        if (dpBuy[i][k] != -1) return dpBuy[i][k];

        long long profit = free(i + 1, k - 1) + prices[i]; // stop long
        profit = max(profit, buy(i + 1, k));               // continue long

        return dpBuy[i][k] = profit;
    }

    long long sell(int i, int k) {
        if (i >= n || k <= 0) return LLONG_MIN / 2;
        if (dpSell[i][k] != -1) return dpSell[i][k];

        long long profit = free(i + 1, k - 1) - prices[i]; // stop short
        profit = max(profit, sell(i + 1, k));              // continue short

        return dpSell[i][k] = profit;
    }
};
