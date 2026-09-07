/*
 * 778. Swim in Rising Water
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 13 ms (beats 28.6%)
 * Memory: 14.5 MB (beats 32.6%)
 * Submitted: 2026-02-22 10:39:44 UTC
 * URL: https://leetcode.com/submissions/detail/1927330681/
 */

class Solution {
  public:
    int swimInWater(vector<vector<int>> &grid) {
        int n = grid.size();
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

        int lo = INT_MAX, hi = INT_MIN;
        for(int r = 0; r < n; ++r) {
            for(int c = 0; c < n; ++c) {
                lo = min(lo, grid[r][c]);
                hi = max(hi, grid[r][c]);
            }
        }

        int l = lo, r = hi;
        while(l < r) {
            int m = l + (r - l) / 2;
            if(validator(grid, n, dirs, m)) r = m;
            else l = m + 1;
        }

        return l;
    }

    bool validator(vector<vector<int>> &grid, int n, vector<pair<int, int>> &dirs, int level) {
        if(grid[0][0] > level) return false;

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        q.push({0, 0});
        visited[0][0] = true;

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if(r == n - 1 && c == n - 1) return true;

            for(auto [y, x] : dirs) {
                int nr = r + y, nc = c + x;

                if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                if(visited[nr][nc]) continue;
                if(grid[nr][nc] > level) continue;

                q.push({nr, nc});
                visited[nr][nc] = true;
            }
        }

        return false;
    }
};
