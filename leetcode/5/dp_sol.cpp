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
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        pair<int, int> res = {0, 0};

        for (int l = 0; l < n; ++l) {
            for (int r = l; r < n; ++r) {
                dfs(s, res, dp, l, r);
            }
        }
        return s.substr(res.first, res.second - res.first + 1);
    };

    bool dfs(string &s, pair<int, int> &res, vector<vector<int>> &dp, int l, int r) {
        if (l > r) return 1;
        if (l == r) return 1;
        if (dp[l][r] != -1) return dp[l][r];

        bool isPal = s[l] == s[r] && dfs(s, res, dp, l + 1, r - 1);
        if (isPal && r - l + 1 > res.second - res.first + 1) res = {l, r};

        return dp[l][r] = isPal;
    }
};
