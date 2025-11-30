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
    int n;
    vector<vector<int>> dirs;
    vector<vector<vector<int>>> dp;

    int swimInWater(vector<vector<int>> &grid) {
        this->n = grid.size();
        this->dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int maxLvl = 0;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                maxLvl = max(maxLvl, grid[r][c]);
            }
        }

        this->dp = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(n + 1, vector<int>(maxLvl, -1)));

        for (int t = 0; t < maxLvl; t++) {
            if (dfs(grid, dp, 0, 0, t)) return t;
        }

        return maxLvl;
    }

    bool dfs(vector<vector<int>> &grid, vector<vector<vector<int>>> &dp, int r, int c, int t) {
        if (r < 0 || r >= n || c < 0 || c >= n || grid[r][c] > t) return false;
        if (dp[r][c][t] != -1) return dp[r][c][t];
        if (r == n - 1 && c == n - 1) return true;

        dp[r][c][t] = false;
        for (vector<int> dir : dirs) {
            int nr = r + dir[0], nc = c + dir[1];
            if (dfs(grid, dp, nr, nc, t)) return dp[r][c][t] = true;
        }

        return dp[r][c][t];
    }
};
