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
    vector<vector<int>> dp;

  public:
    int longestCommonSubsequence(string text1, string text2) {
        this->dp.resize(text1.size() + 1, vector<int>(text2.size() + 1, -1));
        return dfs(text1, text2, 0, 0);
    }

    int dfs(string &text1, string &text2, int i, int j) {
        if (i >= text1.size() || j >= text2.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int best = 0;
        if (text1[i] == text2[j])
            best = max(best, 1 + dfs(text1, text2, i + 1, j + 1));
        else
            best = max(best, max(dfs(text1, text2, i + 1, j), dfs(text1, text2, i, j + 1)));

        return dp[i][j] = best;
    }
};
