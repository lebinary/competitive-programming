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
    int getMaximumGold(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> lookup;
        lookup.assign(m, vector<int>(n, 0));

        int i = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                lookup[r][c] = i++;
            }
        }

        int best = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c]) {
                    queue<tuple<int, int, int, int>> q;
                    q.push({r, c, grid[r][c], 1 << lookup[r][c]});

                    while (!q.empty()) {
                        auto [r, c, gold, mask] = q.front();
                        q.pop();
                        best = max(best, gold);

                        for (auto dir : dirs) {
                            int nr = r + dir[0], nc = c + dir[1];
                            if (nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] == 0) continue;

                            int newIdx = lookup[nr][nc];
                            if ((mask & (1 << newIdx)) == 0) {
                                q.push({nr, nc, gold + grid[nr][nc], mask | (1 << newIdx)});
                            }
                        }
                    }
                }
            }
        }

        return best;
    }
};
