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
    int maximumSafenessFactor(vector<vector<int>> &grid) {
        if (grid[0][0] == 1) return 0;

        int R = grid.size(), C = grid[0].size(), best = 0;
        vector<vector<int>> DIRS = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<int>> score(R, vector<int>(C, 0));
        queue<vector<int>> q;
        vector<vector<bool>> seen(R, vector<bool>(C, false));

        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (grid[r][c] == 1) {
                    q.push({r, c});
                    seen[r][c] = true;
                }
            }
        }

        int maxScore = 0;
        while (!q.empty()) {
            vector<int> &top = q.front();
            int r = top[0], c = top[1];
            q.pop();

            for (auto &dir : DIRS) {
                int nr = r + dir[0], nc = c + dir[1];
                if (nr < 0 || nr >= R || nc < 0 || nc >= C || seen[nr][nc] || grid[nr][nc] != 0) continue;
                q.push({nr, nc});
                seen[nr][nc] = true;

                score[nr][nc] = score[r][c] + 1;
                maxScore = max(maxScore, score[nr][nc]);
            }
        }

        int l = 0, r = maxScore;
        while (l < r) {
            int m = l + (r - l + 1) / 2;

            if (validator(grid, R, C, DIRS, q, seen, score, m))
                l = m;
            else
                r = m - 1;
        }

        return l;
    };

    bool validator(vector<vector<int>> &grid, int R, int C, vector<vector<int>> &DIRS, queue<vector<int>> &q, vector<vector<bool>> &seen, vector<vector<int>> &score, int safeness) {
        if (score[0][0] < safeness) return false;

        q = queue<vector<int>>();
        q.push({0, 0});
        seen.assign(R, vector<bool>(C, false));
        seen[0][0] = true;

        while (!q.empty()) {
            vector<int> &top = q.front();
            int r = top[0], c = top[1];
            q.pop();

            if (r == R - 1 && c == C - 1) return true;

            for (auto &dir : DIRS) {
                int nr = r + dir[0], nc = c + dir[1];

                if (nr < 0 || nr >= R || nc < 0 || nc >= C || seen[nr][nc] || grid[nr][nc] != 0 || score[nr][nc] < safeness) continue;
                q.push({nr, nc});
                seen[nr][nc] = true;
            }
        }

        return false;
    }
};
