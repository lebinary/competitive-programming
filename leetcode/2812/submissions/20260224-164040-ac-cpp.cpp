/*
 * 2812. Find the Safest Path in a Grid
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 434 ms (beats 55.1%)
 * Memory: 170.8 MB (beats 47.0%)
 * Submitted: 2026-02-24 16:40:40 UTC
 * URL: https://leetcode.com/submissions/detail/1929876524/
 */

class Solution {
  public:
    int maximumSafenessFactor(vector<vector<int>> &grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return 0;
        
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        vector<vector<int>> scores(n, vector<int>(n, 0));
        vector<vector<int>> seen(n, vector<int>(n, false));
        queue<pair<int, int>> q;

        for(int r = 0; r < n; ++r) {
            for(int c = 0; c < n; ++c) {
                if(grid[r][c] == 1) {
                    q.push({r, c});
                    seen[r][c] = true;
                }
            }
        }

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for(auto &dir : dirs) {
                int nr = r + dir[0], nc = c + dir[1];

                if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                if(seen[nr][nc]) continue;
                if(grid[nr][nc] == 1) continue;

                scores[nr][nc] = scores[r][c] + 1;
                q.push({nr, nc});
                seen[nr][nc] = true;
            }
        }

        int l = 0, r = 2*n;
        while(l < r) {
            int m = l + (r - l + 1) / 2;

            if(validator(scores, seen, dirs, n, m)) l = m;
            else r = m - 1;
        }

        return l;
    };

    bool validator(vector<vector<int>> &scores, vector<vector<int>> &seen, vector<vector<int>> &dirs, int n, int res) {
        if(scores[0][0] < res || scores[n-1][n-1] < res) return false;
        seen.assign(n, vector<int>(n, false));

        queue<pair<int, int>> q;
        q.push({0, 0});
        seen[0][0] = true;

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if(r == n - 1 && c == n - 1) return true;
            for(auto &dir : dirs) {
                int nr = r + dir[0], nc = c + dir[1];

                if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                if(seen[nr][nc]) continue;
                if(scores[nr][nc] < res) continue;
                
                q.push({nr, nc});
                seen[nr][nc] = true;
            }
        }

        return false;
    }
};
