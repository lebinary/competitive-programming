#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) return false;

    int n = nums.size();
    int target = sum / 2;

    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int num : nums) {
      vector<bool> newdp = dp;
      for (int i = 0; i <= target; ++i) {
        if (i >= num) {
          newdp[i] = dp[i] || dp[i - num];
        }
      }
      dp = newdp;
    }

    return dp[target];
  }
};
