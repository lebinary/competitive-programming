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
    void wallsAndGates(vector<vector<int>> &rooms) {
        int R = rooms.size(), C = rooms[0].size(), INF = pow(2, 31) - 1;
        vector<vector<int>> DIRS = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        queue<vector<int>> q;

        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (rooms[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        while (!q.empty()) {
            int n = q.size();

            for (int i = 0; i < n; ++i) {
                vector<int> itm = q.front();
                int r = itm[0], c = itm[1];
                q.pop();

                for (vector<int> dir : DIRS) {
                    int nr = r + dir[0], nc = c + dir[1];
                    if (nr < 0 || nr >= R || nc < 0 || nc >= C || rooms[nr][nc] == -1 || rooms[nr][nc] != INF) continue;
                    q.push({nr, nc});
                    rooms[nr][nc] = rooms[r][c] + 1;
                }
            }
        }
    }
};
