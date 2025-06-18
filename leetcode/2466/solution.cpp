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
    vector<int> dp;
    int mod;

  public:
    int countGoodStrings(int low, int high, int zero, int one) {
        this->dp.assign(high + 1, -1);
        this->mod = 1e9 + 7;
        return dfs(0, low, high, zero, one);
    }

    int dfs(int l, int low, int high, int zero, int one) {
        if (l > high) return 0;
        if (dp[l] != -1) return dp[l];
        int res = l >= low ? 1 : 0;
        res += dfs(l + zero, low, high, zero, one);
        res += dfs(l + one, low, high, zero, one);
        return dp[l] = (res % mod);
    }
};
