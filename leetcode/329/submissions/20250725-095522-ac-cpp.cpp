/*
 * 329. Longest Increasing Path in a Matrix
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 7 ms (beats 81.9%)
 * Memory: 21.9 MB (beats 33.6%)
 * Submitted: 2025-07-25 09:55:23 UTC
 * URL: https://leetcode.com/submissions/detail/1710813216/
 */


class Solution {
  public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> memo = vector<vector<int>>(m, vector<int>(n, -1));

        int best = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                best = max(best, dfs(matrix, memo, dirs, m, n, r, c));
            }
        }

        return best;
    }

    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &memo, vector<vector<int>> &dirs, int m, int n, int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >= n) return 0;
        if (memo[r][c] != -1) return memo[r][c];

        int best = 1;
        for (vector<int> &d : dirs) {
            int nr = r + d[0], nc = c + d[1];

            if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
            if (matrix[nr][nc] > matrix[r][c]) {
                best = max(best, 1 + dfs(matrix, memo, dirs, m, n, nr, nc));
            }
        }

        return memo[r][c] = best;
    }
};
