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
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[n] = true;

        for (int start = n - 1; start >= 0; --start) {
            for (int end = n; end > start; --end) {
                if (dp[end] && dict.count(s.substr(start, end - start))) {
                    dp[start] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};
