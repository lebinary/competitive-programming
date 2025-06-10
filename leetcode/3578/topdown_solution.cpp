#include <cctype>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    vector<int> nums;
    int n;
    int k;
    int mod;
    vector<int> dp;

  public:
    int countPartitions(vector<int> &nums, int k) {
        this->mod = pow(10, 9) + 7;
        this->nums = nums;
        this->k = k;
        this->n = nums.size();
        this->dp.assign(n + 1, -1);
        return dfs(0);
    }

    int dfs(int i) {
        if (i >= n) return 1;
        // if (dp[i] != -1) return dp[i];
        int res = 0;

        // no expand
        res += dfs(i + 1);

        // expand
        int currMin = nums[i], currMax = nums[i];
        for (int j = i + 1; j < n; ++j) {
            if (abs(currMax - currMin) > k || currMin > currMax) break;
            currMin = min(currMin, nums[j]);
            currMax = max(currMax, nums[j]);
            res += dfs(j);
        }

        cout << nums[i] << " : " << res << endl;
        return dp[i] = res;
    };
};
