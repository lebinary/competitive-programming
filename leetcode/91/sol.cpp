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
    vector<int> dp;
    int numDecodings(string s) {
        int n = s.size();
        this->dp.resize(n + 1, -1);

        return dfs(s, dp, n, 0);
    }

    bool valid(char l, char r) {
        if (l != '1' && l != '2') return false;
        if (l == '2' && (r == '7' || r == '8' || r == '9')) return false;
        return true;
    }

    int dfs(string &s, vector<int> &dp, int n, int i) {
        if (i >= n) return 1;
        if (s[i] == '0') return 0;
        if (dp[i] != -1) return dp[i];

        int count = 0;
        count += dfs(s, dp, n, i + 1);

        if (i < n - 1 && valid(s[i], s[i + 1])) {
            count += dfs(s, dp, n, i + 2);
        }

        return dp[i] = count;
    };
};
