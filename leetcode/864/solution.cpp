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
    int shortestPathAllKeys(vector<string> &grid) {
        int R = grid.size(), C = grid[0].size(), K = 0, keySet = 0;
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int startR = 0, startC = 0;
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (isKey(grid[r][c])) K++;
                if (isStart(grid[r][c])) {
                    startR = r;
                    startC = c;
                }
            }
        }
        vector<vector<vector<bool>>> visited(R + 1, vector<vector<bool>>(C + 1, vector<bool>(pow(2, K), 0)));

        queue<vector<int>> q;
        q.push({startR, startC, keySet, 0});

        while (!q.empty()) {
            vector<int> &top = q.front();
            int r = top[0], c = top[1], keySet = top[2], len = top[3];
            q.pop();

            if (isKey(grid[r][c])) keySet |= (1 << (grid[r][c] - 'a'));
            if (keySet == pow(2, K) - 1) return len;

            for (auto [y, x] : dirs) {
                int nr = r + y, nc = c + x;
                if (nr < 0 || nr >= R || nc < 0 || nc >= C || isWall(grid[nr][nc]) || visited[nr][nc][keySet] || (isLock(grid[nr][nc]) && !(keySet & (1 << (grid[nr][nc] - 'A'))))) continue;
                q.push({nr, nc, keySet, len + 1});
                visited[nr][nc][keySet] = true;
            }
        }

        return -1;
    };

    bool isKey(char c) { return isalpha(c) && islower(c); }
    bool isLock(char c) { return isalpha(c) && isupper(c); }
    bool isWall(char c) { return c == '#'; }
    bool isStart(char c) { return c == '@'; }
};
