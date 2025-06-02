#include <climits>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> coins;
  vector<int> dp;

  int coinChange(vector<int> &coins, int amount) {
    this->coins = coins;
    this->dp.assign(amount + 1, -1);

    int res = dfs(amount);
    return res == INT_MAX ? -1 : res;
  }

  int dfs(int curr) {
    if (curr == 0) return 0;
    if (curr < 0) return INT_MAX;
    if (dp[curr] != -1) return dp[curr];

    int best = INT_MAX;
    for (int coin : coins) {
      best = min(best, dfs(curr - coin));
    }

    return dp[curr] = best == INT_MAX ? INT_MAX : 1 + best;
  }
};
