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
    int jump(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp = vector<int>(n, n);
        dp[n - 1] = 0;

        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= nums[i]; ++j) {
                if (i + j >= n) break;
                dp[i] = min(dp[i], dp[i + j] + 1);
            }
        }

        return dp[0];
    }
};
