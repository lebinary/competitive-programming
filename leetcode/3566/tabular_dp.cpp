#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool checkEqualPartitions(vector<int> &nums, long long target) {
    vector<vector<bool>> dp(target + 1, vector<bool>(target + 1, false));
    dp[1][1] = true; // Base case: empty groups have product 1

    for (int num : nums) {
      vector<vector<bool>> newdp = dp;
      for (int a = 1; a <= target; ++a) {
        for (int b = 1; b <= target; ++b) {
          if (a % num == 0) newdp[a][b] = newdp[a][b] || dp[a / num][b];
          if (b % num == 0) newdp[a][b] = newdp[a][b] || dp[a][b / num];
        }
      }
      dp = newdp;
    }

    return dp[target][target];
  }
};
