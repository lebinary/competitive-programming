#include <algorithm>
#include <cctype>
#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return dfs(dp, s, t, n, m, 0, 0);
    }

    int dfs(vector<vector<int>> &dp, string &s, string &t, int n, int m, int i, int j) {
        if (j >= m) return 1;
        if (i >= n) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int agg = 0;
        if (s[i] == t[j]) agg += dfs(dp, s, t, n, m, i + 1, j + 1);
        agg += dfs(dp, s, t, n, m, i + 1, j);

        return dp[i][j] = agg;
    }
};
