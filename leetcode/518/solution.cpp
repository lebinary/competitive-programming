#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int change(int amount, vector<int> &coins) {
    vector<uint> dp(amount + 1, 0);
    dp[0] = 1;

    for (int coin : coins) {
      for (int a = coin; a <= amount; ++a) {
        dp[a] += dp[a - coin];
      }
    }

    return (int)dp[amount];
  }
};
