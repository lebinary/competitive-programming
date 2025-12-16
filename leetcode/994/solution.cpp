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
    int orangesRotting(vector<vector<int>> &grid) {
        int R = grid.size(), C = grid[0].size(), freshCount = 0, t = 0;
        vector<vector<int>> DIRS = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        queue<pair<int, int>> q;

        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (grid[r][c] == 2)
                    q.push({r, c});
                else if (grid[r][c] == 1)
                    freshCount++;
            }
        }

        while (!q.empty() && freshCount > 0) {
            int n = q.size();
            for (int _ = 0; _ < n; ++_) {
                pair<int, int> itm = q.front();
                q.pop();
                int r = itm.first, c = itm.second;

                for (vector<int> dir : DIRS) {
                    int nr = r + dir[0], nc = c + dir[1];
                    if (nr < 0 || nr >= R || nc < 0 || nc >= C || grid[nr][nc] != 1) continue;
                    q.push({nr, nc});
                    grid[nr][nc] = 2;
                    freshCount--;
                }
            }
            t++;
        }

        return freshCount == 0 ? t : -1;
    }
};
