/*
 * 48. Rotate Image
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 10.1 MB (beats 70.3%)
 * Submitted: 2025-07-11 14:14:31 UTC
 * URL: https://leetcode.com/submissions/detail/1694326154/
 */


class Solution {
  public:
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();

        // vertically inverse
        for (int r = 0; r < n / 2; ++r) {
            for (int c = 0; c < n; ++c) {
                swap(matrix[r][c], matrix[n - r - 1][c]);
            }
        }

        // transpose
        for (int r = 0; r < n; ++r) {
            for (int c = r + 1; c < n; ++c) {
                swap(matrix[r][c], matrix[c][r]);
            }
        }
    }
};
