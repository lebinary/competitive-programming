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
    vector<vector<int>> dp;
    int uniquePaths(int m, int n) {
        this->dp.resize(m, vector<int>(n, -1));
        return dfs(m, n, 0, 0);
    }

    int dfs(int m, int n, int r, int c) {
        if (r >= m || c >= n) return 0;
        if (r == m - 1 && c == n - 1) return 1;
        if (dp[r][c] != -1) return dp[r][c];

        int count = 0;
        count += dfs(m, n, r + 1, c);
        count += dfs(m, n, r, c + 1);

        return dp[r][c] = count;
    }
};
