/*
 * 54. Spiral Matrix
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 9.4 MB (beats 18.2%)
 * Submitted: 2026-01-16 10:19:23 UTC
 * URL: https://leetcode.com/submissions/detail/1886690600/
 */

class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int R = matrix.size(), C = matrix[0].size(), d = 0, r = 0, c = 0;
        vector<vector<int>> DIRS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> res;

        while (res.size() < R * C) {
            res.push_back(matrix[r][c]);
            matrix[r][c] = 999;

            int nr = r + DIRS[d][0], nc = c + DIRS[d][1];
            if (nr >= R || nr < 0 || nc >= C || nc < 0 || matrix[nr][nc] == 999) {
                d = (d + 1) % 4;
            }

            r += DIRS[d][0];
            c += DIRS[d][1];
        }

        return res;
    };
};
