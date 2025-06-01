#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> nums;
  int target;
  unordered_map<long, int> dp;

  int findTargetSumWays(vector<int> &nums, int target) {
    this->nums = nums;
    this->target = target;

    return dfs(0, 0);
  }

  long encode(int total, int i) { return static_cast<long>(total) << 32 | static_cast<long>(i); }

  // O(2^n)
  int dfs(int total, int i) {
    if (i >= nums.size()) {
      if (total == target) return 1;
      return 0;
    }

    long key = encode(total, i);
    if (dp.find(key) != dp.end()) return dp[key];

    int res = dfs(total + nums[i], i + 1) + dfs(total - nums[i], i + 1);
    return dp[key] = res;
  }
};
