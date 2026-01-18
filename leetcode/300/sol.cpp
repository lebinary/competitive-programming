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
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return dfs(dp, nums, n, -1, 0);
    }

    int dfs(vector<vector<int>> &dp, vector<int> &nums, int n, int previ, int i) {
        if (i >= n) return 0;
        if (dp[previ + 1][i] != -1) return dp[previ + 1][i];

        int best = dfs(dp, nums, n, previ, i + 1);
        if (previ == -1 || nums[previ] < nums[i]) {
            best = max(best, 1 + dfs(dp, nums, n, i, i + 1));
        };

        return dp[previ + 1][i] = best;
    }
};
