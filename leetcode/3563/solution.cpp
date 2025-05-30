#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool isConsec(char a, char b) { return abs(a - b) % 24 == 1; }

  string lexicographicallySmallestString(string s) {
    int n = s.size();
    vector<vector<string>> dp(n + 1, vector<string>(n + 1, ""));

    // Fill DP table for all substring lengths
    for (int len = 1; len <= n; len++) {
      for (int i = 0; i + len <= n; i++) {
        int j = i + len;

        string res = s[i] + dp[i + 1][j];

        // Try removing each consecutive pair
        for (int k = i + 1; k < j; k++) {
          if (isConsec(s[i], s[k]) &&
              dp[i + 1][k] == "") { // second cond to check if the space between
                                    // s[i] and s[k] can be removed
            res = min(res, dp[k + 1][j]); // removed s[i-k] left with dp[k+1, j]
          }
        }

        dp[i][j] = res;
      }
    }

    return dp[0][n];
  }
};
