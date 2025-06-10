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
    unordered_map<string, int> dp;

  public:
    int countPartitions(vector<int> &nums, int k) {
        this->mod = pow(10, 9) + 7;
        this->nums = nums;
        this->k = k;
        this->n = nums.size();

        return dfs(1, nums[0], nums[0]);
    }

    string hash(int i, int low, int high) { return to_string(i) + to_string(low) + to_string(high); }

    // O(2^n) -> not great
    int dfs(int i, int low, int high) {
        if (i >= n) return 1;
        if (low > high) return 0;

        string h = hash(i, low, high);
        if (dp.find(h) != dp.end()) return dp[h];

        int res = 0;

        // split
        res = (res % mod) + dfs(i + 1, nums[i], nums[i]);

        // no split (merge)
        if (nums[i] < low && abs(high - nums[i]) <= k) {
            res = (res % mod) + dfs(i + 1, nums[i], high);
        } else if (nums[i] > high && abs(nums[i] - low) <= k) {
            res = (res % mod) + dfs(i + 1, low, nums[i]);
        } else if (low <= nums[i] && nums[i] <= high) {
            res = (res % mod) + dfs(i + 1, low, high);
        }

        return dp[h] = res % mod;
    }
};
