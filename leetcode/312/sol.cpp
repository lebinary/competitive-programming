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
    int maxCoins(vector<int> &nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));
        return dfs(nums, dp, n, 1, n - 1);
    }

    int dfs(vector<int> &nums, vector<vector<int>> &dp, int n, int l, int r) {
        if (l >= r) return 0;
        if (dp[l][r] != -1) return dp[l][r];

        int best = 0;
        for (int k = l; k < r; k++) {
            int coins = nums[l - 1] * nums[k] * nums[r];
            best = max(best, coins + dfs(nums, dp, n, l, k) + dfs(nums, dp, n, k + 1, r));
        }

        return dp[l][r] = best;
    }
};
