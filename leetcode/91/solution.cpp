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
        return dfs(s, 0);
    }

    int dfs(string &s, int i) {
        if (i >= s.size()) return 1;
        if (s[i] == '0') return 0;
        if (dp[i] != -1) return dp[i];

        int count = 0;
        if (s[i] == '1' && i + 1 < s.size()) {
            count += dfs(s, i + 2);
        } else if (s[i] == '2' && i + 1 < s.size() && (s[i + 1] - '0') <= 6) {
            count += dfs(s, i + 2);
        }
        count += dfs(s, i + 1);

        return dp[i] = count;
    }
};
