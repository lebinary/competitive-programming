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
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> dp(n + 1, -1);
        int best = dfs(nums, dp, n - 1, 0);
        dp.assign(n + 1, -1);
        best = max(best, dfs(nums, dp, n, 1));
        return best;
    }

    int dfs(vector<int> &nums, vector<int> &dp, int n, int i) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];

        return dp[i] = max(nums[i] + dfs(nums, dp, n, i + 2), dfs(nums, dp, n, i + 1));
    }
};
