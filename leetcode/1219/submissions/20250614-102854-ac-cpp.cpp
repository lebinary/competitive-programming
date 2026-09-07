/*
 * 1219. Path with Maximum Gold
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 183 ms (beats 26.5%)
 * Memory: 10.9 MB (beats 30.1%)
 * Submitted: 2025-06-14 10:28:55 UTC
 * URL: https://leetcode.com/submissions/detail/1663753558/
 */


class Solution {
    vector<vector<bool>> visited;
    vector<vector<int>> grid;
    vector<vector<int>> dirs;
    int m;
    int n;

  public:
    int getMaximumGold(vector<vector<int>> &grid) {
        this->grid = grid;
        this->m = grid.size();
        this->n = grid[0].size();
        this->visited.assign(m, vector<bool>(n, false));
        this->dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int best = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c]) {
                    best = max(best, dfs(r, c));
                }
            }
        }

        return best;
    }

    int dfs(int r, int c) {
        if (r >= m || r < 0 || c >= n || c < 0 || grid[r][c] == 0 || visited[r][c]) return 0;
        visited[r][c] = true;

        int bestDir = 0;
        for (auto &dir : dirs) {
            int nextR = r + dir[0], nextC = c + dir[1];
            bestDir = max(bestDir, dfs(nextR, nextC));
        }

        visited[r][c] = false;
        return bestDir + grid[r][c];
    }
};
