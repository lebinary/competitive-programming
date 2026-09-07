/*
 * 73. Set Matrix Zeroes
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 19 MB (beats 100.0%)
 * Submitted: 2025-07-25 09:10:14 UTC
 * URL: https://leetcode.com/submissions/detail/1710766631/
 */


class Solution {
  public:
    void setZeroes(vector<vector<int>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        unordered_set<int> rows, cols;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rows.count(i) || cols.count(j)) matrix[i][j] = 0;
            }
        }
    }
};
