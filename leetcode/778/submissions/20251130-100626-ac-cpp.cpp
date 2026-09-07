/*
 * 778. Swim in Rising Water
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 160 ms (beats 5.0%)
 * Memory: 351 MB (beats 5.1%)
 * Submitted: 2025-11-30 10:06:26 UTC
 * URL: https://leetcode.com/submissions/detail/1843240060/
 */

class Solution {
  public:
    int n;
    vector<vector<int>> dirs;
    vector<vector<vector<int>>> dp;

    int swimInWater(vector<vector<int>> &grid) {
        this->n = grid.size();
        this->dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int maxT = 0;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                maxT = max(maxT, grid[r][c]);
            }
        }

        this->dp = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(n + 1, vector<int>(maxT, -1)));

        int l = 0, r = maxT;
        while (l < r) {
            int m = l + (r - l) / 2;

            if (dfs(grid, dp, 0, 0, m))
                r = m;
            else
                l = m + 1;
        }

        return l;
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

