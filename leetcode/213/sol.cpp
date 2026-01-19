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
        vector<int> dp(n + 1, -1);
        int best = dfs(nums, dp, n, 0);
        dp.assign(n + 1, -1);
        best = max(best, dfs2(nums, dp, n, 0));
        return best;
    }

    int dfs(vector<int> &nums, vector<int> &dp, int n, int i) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];
        if (i == 0) return dp[i] = nums[i] + dfs(nums, dp, n, i + 2);
        if (i == n - 1) return dp[i] = dfs(nums, dp, n, i + 1);

        return dp[i] = max(dfs(nums, dp, n, i + 1), nums[i] + dfs(nums, dp, n, i + 2));
    }

    int dfs2(vector<int> &nums, vector<int> &dp, int n, int i) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];
        if (i == 0) return dp[i] = dfs2(nums, dp, n, i + 1);
        if (i == n - 1) return dp[i] = nums[i] + dfs2(nums, dp, n, i + 2);

        return dp[i] = max(dfs2(nums, dp, n, i + 1), nums[i] + dfs2(nums, dp, n, i + 2));
    };
};
