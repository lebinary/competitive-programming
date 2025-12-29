#include <algorithm>
#include <cctype>
#include <climits>
#include <format>
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
    int R, C;

    void solve(vector<vector<char>> &board) {
        this->R = board.size(), this->C = board[0].size();

        for (int r = 0; r < R; ++r) {
            dfs(board, r, 0);
            dfs(board, r, C - 1);
        }

        for (int c = 0; c < C; ++c) {
            dfs(board, 0, c);
            dfs(board, R - 1, c);
        }

        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (board[r][c] == 'O') board[r][c] = 'X';
                if (board[r][c] == 'I') board[r][c] = 'O';
            }
        }
    }

    void dfs(vector<vector<char>> &board, int r, int c) {
        if (r < 0 || r >= R || c < 0 || c >= C || board[r][c] != 'O') return;
        board[r][c] = 'I';
        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
        dfs(board, r, c + 1);
        dfs(board, r, c - 1);
    }
};
