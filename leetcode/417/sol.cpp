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
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vector<vector<int>> res;
        vector<vector<char>> visited(m, vector<char>(n, '-'));
        queue<pair<int, int>> q;

        // go as far as possible from Pacific
        for (int r = 0; r < m; ++r) {
            q.push({r, 0});
            visited[r][0] = 'P';
        }
        for (int c = 0; c < n; ++c) {
            q.push({0, c});
            visited[0][c] = 'P';
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (vector<int> &dir : dirs) {
                int nr = r + dir[0], nc = c + dir[1];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || visited[nr][nc] == 'P' || heights[nr][nc] < heights[r][c]) continue;
                visited[nr][nc] = 'P';
                q.push({nr, nc});
            };
        };

        // go as far as possible from Atlantic
        for (int r = 0; r < m; ++r) {
            q.push({r, n - 1});
            if (visited[r][n - 1] == 'P') res.push_back({r, n - 1});
            visited[r][n - 1] = 'A';
        }
        for (int c = 0; c < n; ++c) {
            q.push({m - 1, c});
            if (visited[m - 1][c] == 'P') res.push_back({m - 1, c});
            visited[m - 1][c] = 'A';
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (vector<int> &dir : dirs) {
                int nr = r + dir[0], nc = c + dir[1];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || visited[nr][nc] == 'A' || heights[nr][nc] < heights[r][c]) continue;
                if (visited[nr][nc] == 'P') {
                    res.push_back({nr, nc});
                }

                visited[nr][nc] = 'A';
                q.push({nr, nc});
            }
        }

        return res;
    }
};
