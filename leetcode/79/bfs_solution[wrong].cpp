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

/** BFS won't work here because we if there are 2 or more valid paths, we need to exhausively explore both */
class Solution {
  public:
    bool exist(vector<vector<char>> &board, string word) {
        int m = board.size(), n = board[0].size(), w = word.size();
        vector<vector<int>> dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (board[r][c] != word[0]) continue;

                queue<vector<int>> q;
                vector<vector<bool>> visited(m, vector<bool>(n, false));
                q.push({r, c, 0});

                while (!q.empty()) {
                    vector<int> curr = q.front();
                    q.pop();
                    int cr = curr[0], cc = curr[1], ci = curr[2];
                    visited[cr][cc] = true;

                    if (ci == w - 1) return true;
                    for (vector<int> dir : dirs) {
                        int nr = dir[0] + cr, nc = dir[1] + cc, ni = ci + 1;
                        if (nr >= m || nr < 0 || nc >= n || nc < 0 || visited[nr][nc] || board[nr][nc] != word[ni]) continue;
                        q.push({nr, nc, ni});
                    }
                }
            }
        }

        return false;
    }
};
