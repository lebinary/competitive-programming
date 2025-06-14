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
  public:
    long long maximumProfit(vector<int> &prices, int k) {
        int n = prices.size();

        // z=0: free, z=1: long, z=2: short
        vector<vector<vector<long long>>> dp;
        dp.resize(3, vector<vector<long long>>(n + 1, vector<long long>(k + 1, 0)));

        for (int i = 0; i <= n; i++) {
            dp[1][i][k] = LLONG_MIN / 2; // buy position invalid
        }
        for (int j = 0; j <= k; j++) {
            dp[2][n][j] = LLONG_MIN / 2; // sell position invalid
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = k - 1; j >= 0; --j) {
                // int freePos = 0, longPos = 1, shortPos = 2;
                dp[0][i][j] = max({dp[0][i + 1][j], dp[1][i + 1][j] - prices[i], dp[2][i + 1][j] + prices[i]});
                dp[1][i][j] = max({dp[0][i + 1][j + 1] + prices[i], dp[1][i + 1][j]});
                dp[2][i][j] = max({dp[0][i + 1][j + 1] - prices[i], dp[2][i + 1][j]});
            }
        }

        return dp[0][0][0];
    };
};
