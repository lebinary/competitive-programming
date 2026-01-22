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
