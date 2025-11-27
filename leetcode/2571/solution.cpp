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
    unordered_map<int, int> dp;

    int minOperations(int n) { return dfs(n); };

    int dfs(int n) {
        if (n == 0) return 0;
        if (dp.count(n)) return dp[n];

        int bits = 32 - __builtin_clz(abs(n));

        int best = INT_MAX;
        for (int i = 0; i <= bits; ++i) {
            int num = 1 << i;
            int res = n > 0 ? dfs(n - num) : dfs(n + num);
            if (res != INT_MAX) best = min(best, res);
        }

        return dp[n] = best == INT_MAX ? INT_MAX : 1 + best;
    }
};
