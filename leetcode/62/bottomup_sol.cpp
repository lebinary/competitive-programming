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
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        dp[m - 1][n - 1] = 1;
        for (int r = m - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {
                dp[r][c] += dp[r + 1][c] + dp[r][c + 1];
            }
        }
        return dp[0][0];
    }
};
