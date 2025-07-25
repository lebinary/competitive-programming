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
