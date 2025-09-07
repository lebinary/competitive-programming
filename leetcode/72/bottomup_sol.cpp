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
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp = vector<vector<int>>(n + 1, vector<int>(m + 1, INT_MAX));

        dp[n][m] = 0;
        for (int i = 0; i < n; ++i) dp[i][m] = n - i;
        for (int j = 0; j < m; ++j) dp[n][j] = m - j;

        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                    continue;
                }
                dp[i][j] = 1 + min({dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1]});
            }
        }

        return dp[0][0];
    }
};
