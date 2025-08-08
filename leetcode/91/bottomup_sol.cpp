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
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp = vector<int>(n + 1, -1);
        dp[n] = 1;

        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') {
                dp[i] = 0;
                continue;
            };

            dp[i] = dp[i + 1];
            if (s[i] == '1' && i + 1 < n)
                dp[i] += dp[i + 2];
            else if (s[i] == '2' && i + 1 < n && (s[i + 1] - '0') <= 6)
                dp[i] += dp[i + 2];
        }

        return dp[0];
    }
};
