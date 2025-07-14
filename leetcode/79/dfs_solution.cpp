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
    vector<vector<int>> DIRS;
    int ROWS, COLS;

  public:
    bool exist(vector<vector<char>> &board, string word) {
        this->DIRS = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        this->ROWS = board.size();
        this->COLS = board[0].size();

        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (board[r][c] != word[0]) continue;
                if (dfs(board, word, r, c, 0)) return true;
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>> &board, string &word, int r, int c, int i) {
        if (i >= word.size()) return true;
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS || board[r][c] == '#' || board[r][c] != word[i]) return false;

        board[r][c] = '#';

        bool found = false;
        for (vector<int> dir : DIRS) {
            int nr = r + dir[0], nc = c + dir[1];

            if (dfs(board, word, nr, nc, i + 1)) {
                found = true;
                break;
            }
        }

        board[r][c] = word[i];
        return found;
    }
};
