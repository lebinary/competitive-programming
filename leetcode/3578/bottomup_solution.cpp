#include <cctype>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    int countPartitions(vector<int> &nums, int k) {
        int mod = pow(10, 9) + 7;
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        int res = 0;
        for (int i = 1; i <= n; ++i) {
            int num = nums[i - 1];

            int currMin = INT_MAX, currMax = INT_MIN;
            for (int j = i; j > 0; --j) {
                currMin = min(currMin, nums[j - 1]);
                currMax = max(currMax, nums[j - 1]);
                if (abs(currMax - currMin) > k) break;

                dp[i] = (dp[i] % mod) + (dp[j - 1] % mod);
            }
        }

        return dp[n] % mod;
    }
};
