/*
 * 36. Valid Sudoku
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 5 ms (beats 33.6%)
 * Memory: 23.1 MB (beats 51.8%)
 * Submitted: 2026-01-22 10:12:23 UTC
 * URL: https://leetcode.com/submissions/detail/1893133005/
 */


class Solution {
  public:
    bool isValidSudoku(vector<vector<char>> &board) {
        vector<vector<bool>> rows(9, vector<bool>(10, false));
        vector<vector<bool>> cols(9, vector<bool>(10, false));
        vector<vector<bool>> boxes(9, vector<bool>(10, false));

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') continue;

                int val = board[r][c] - '0';
                int b = (r / 3) * 3 + c / 3;
                if (rows[r][val] || cols[c][val] || boxes[b][val]) return false;
                rows[r][val] = true;
                cols[c][val] = true;
                boxes[b][val] = true;
            }
        }
        return true;
    };
};

