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
    vector<vector<int>> grid;
    vector<vector<int>> dirs;
    int m;
    int n;

  public:
    int getMaximumGold(vector<vector<int>> &grid) {
        this->grid = grid;
        this->m = grid.size();
        this->n = grid[0].size();
        this->dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int best = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c]) {
                    best = max(best, dfs(r, c));
                }
            }
        }

        return best;
    }

    int dfs(int r, int c) {
        if (r >= m || r < 0 || c >= n || c < 0 || grid[r][c] == 0) return 0;
        int tmp = grid[r][c];
        grid[r][c] = 0;

        int bestDir = 0;
        for (auto &dir : dirs) {
            int nextR = r + dir[0], nextC = c + dir[1];
            bestDir = max(bestDir, dfs(nextR, nextC));
        }

        grid[r][c] = tmp;
        return bestDir + grid[r][c];
    }
};
