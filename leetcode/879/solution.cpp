#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit) {
    int mod = 1e9 + 7;

    // dp[i][j] = ways to achieve at least j profit using at most i members
    vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1, 0));

    // 0 profit can always be achieved with any number of members
    for (int i = 0; i <= n; i++) {
      dp[i][0] = 1;
    }

    for (int k = 0; k < group.size(); ++k) {
      vector<vector<int>> newdp = dp;

      for (int i = 0; i <= n; ++i) {
        if (i < group[k]) continue;

        for (int j = 0; j <= minProfit; ++j) {
          int newProfit = max(0, j - profit[k]);
          newdp[i][j] = (dp[i][j] + dp[i - group[k]][newProfit]) % mod;
        }
      }

      dp = newdp;
    }

    return dp[n][minProfit];
  }
};
