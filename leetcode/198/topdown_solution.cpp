#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// Top down DP
class Solution {
public:
  vector<int> dp;
  vector<int> nums;

  int rob(vector<int> &nums) {
    int n = nums.size();
    this->nums = nums;
    this->dp.assign(n + 1, -1);

    return dfs(0);
  }

  int dfs(int i) {
    if (i >= nums.size()) return 0;
    if (dp[i] != -1) return dp[i];
    int res = max(nums[i] + dfs(i + 2), dfs(i + 1));
    return dp[i] = res;
  }
};
