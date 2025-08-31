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
    vector<vector<int>> dp;
    int minDistance(string word1, string word2) {
        this->dp.resize(word1.size(), vector<int>(word2.size(), -1));
        return dfs(word1, word2, 0, 0);
    }

    int dfs(string &word1, string &word2, int i, int j) {
        if (i >= word1.size() && j >= word2.size()) return 0;
        if (i >= word1.size()) return word2.size() - j;
        if (j >= word2.size()) return word1.size() - i;
        if (dp[i][j] != -1) return dp[i][j];

        if (word1[i] == word2[j]) return dp[i][j] = dfs(word1, word2, i + 1, j + 1);

        int best = INT_MAX;
        // insert
        best = min(best, 1 + dfs(word1, word2, i, j + 1));

        // remove
        best = min(best, 1 + dfs(word1, word2, i + 1, j));

        // replace
        best = min(best, 1 + dfs(word1, word2, i + 1, j + 1));

        return dp[i][j] = best;
    }
};
