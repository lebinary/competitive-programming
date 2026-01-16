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

        vector<int> dp(s.size() + 1, -1);
        return dfs(s, dp, dict, 0);
    }

    bool dfs(string &s, vector<int> &dp, unordered_set<string> &dict, int start) {
        if (start >= s.size()) return true;
        if (dp[start] != -1) return dp[start];

        for (int end = start + 1; end <= s.size(); end++) {
            if (dict.count(s.substr(start, end - start)) == 0) continue;

            if (dfs(s, dp, dict, end)) return dp[start] = true;
        }

        return dp[start] = false;
    }
};
