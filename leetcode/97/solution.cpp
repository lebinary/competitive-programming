#include <algorithm>
#include <cctype>
#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
    string s1;
    string s2;
    string s3;
    vector<vector<vector<int>>> dp;

  public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size(), h = s3.size();
        if (s1.size() + s2.size() != s3.size()) return false;

        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        this->dp.resize(m + 1, vector<vector<int>>(n + 1, vector<int>(h + 1, -1)));
        return dfs(0, 0, 0);
    }

    bool dfs(int i, int j, int k) {
        if (k >= s3.size()) return dp[i][j][k] = i + j == k;
        if (dp[i][j][k] != -1) return dp[i][j][k];

        int res = false;
        if (i < s1.size() && s1[i] == s3[k]) res = res || dfs(i + 1, j, k + 1);
        if (j < s2.size() && s2[j] == s3[k]) res = res || dfs(i, j + 1, k + 1);

        return dp[i][j][k] = res;
    }
};
