#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
    int n;
    int k;
    vector<int> prices;

  public:
    long long maximumProfit(vector<int> &prices, int k) {
        // action: 1=long, -1=short, 0=nothing
        this->prices = prices;
        this->n = prices.size();
        this->k = k;

        return dfs(0, 0, 0, 0);
    }

    long long dfs(int i, int action, int profit, int count) {
        if (i >= n || count == k) return profit;

        long long res = LLONG_MIN;
        if (action == 0) {
            res = max(res, dfs(i + 1, 0, profit, count));
            res = max(res, dfs(i + 1, 1, profit - prices[i], count));
            res = max(res, dfs(i + 1, -1, profit + prices[i], count));
        } else if (action == 1) {
            res = max(res, dfs(i + 1, 1, profit, count));
            res = max(res, dfs(i + 1, 0, profit + prices[i], count + 1));
        } else {
            res = max(res, dfs(i + 1, -1, profit, count));
            res = max(res, dfs(i + 1, 0, profit - prices[i], count + 1));
        }

        return res;
    }
};
