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
    vector<vector<int>> dirs;
    vector<vector<int>> grid;
    int m, n;

    int maxAreaOfIsland(vector<vector<int>> &grid) {
        this->dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        this->grid = grid;
        this->m = grid.size(), this->n = grid[0].size();
        int res = 0;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    res = max(res, explore(r, c));
                }
            }
        }

        return res;
    }

    int explore(int r, int c) {
        if (r >= m || c >= n || r < 0 || c < 0 || grid[r][c] == -1 || grid[r][c] == 0) return 0;
        grid[r][c] = -1;

        int size = 1;
        for (auto dir : dirs) {
            int next_r = r + dir[0], next_c = c + dir[1];
            size += explore(next_r, next_c);
        }

        return size;
    }
};
