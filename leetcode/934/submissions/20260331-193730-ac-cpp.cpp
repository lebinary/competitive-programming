/*
 * 934. Shortest Bridge
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 2831 ms (beats 5.0%)
 * Memory: 486.6 MB (beats 5.0%)
 * Submitted: 2026-03-31 19:37:31 UTC
 * URL: https://leetcode.com/submissions/detail/1965247391/
 */

class Solution {
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int n;

public:
    int shortestBridge(vector<vector<int>>& grid) {
        this->n = grid.size();
        
        int islandId = 1;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        for(int r = 0; r < n; ++r) {
            for(int c = 0; c < n; ++c) {
                if(visited[r][c]) continue;
                if(grid[r][c] == 1) {
                    explore(grid, visited, r, c, islandId);
                    islandId++;
                }
            }
        }
        
        int res = INT_MAX;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] != 1) continue;
                if(isInner(grid, i, j)) continue;

                queue<vector<int>> q;
                visited.assign(n, vector<bool>(n, false));
                q.push({i, j, 0});
                visited[i][j] = true;

                while(!q.empty()) {
                    auto& top = q.front();
                    int r = top[0], c = top[1], dist = top[2];
                    q.pop();

                    if(grid[r][c] == 2) {
                        res = min(res, dist - 1);
                        break;
                    }

                    for(auto& dir : dirs) {
                        int nr = r + dir[0], nc = c + dir[1];
                        if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                        if(visited[nr][nc]) continue;

                        int nDist = grid[nr][nc] == 1 ? 0 : dist + 1;
                        q.push({nr, nc, nDist});
                        visited[nr][nc] = true;
                    }
                }
            }
        }

        return res;
    }

    bool isInner(vector<vector<int>>& grid, int r, int c) {
        for(auto& dir : dirs) {
            int nr = r + dir[0], nc = c + dir[1];
            if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
            if(grid[nr][nc] != 1) return false;
        }
        return true;
    }

    void explore(vector<vector<int>>& grid, vector<vector<bool>>& visited, int startR, int startC, int islandId) {
        queue<pair<int, int>> q;

        q.push({startR, startC});
        visited[startR][startC] = true;

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            grid[r][c] = islandId;

            for(auto& dir : dirs) {
                int nr = r + dir[0], nc = c + dir[1];

                if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                if(visited[nr][nc]) continue;
                if(grid[nr][nc] != 1) continue;

                q.push({nr, nc});
                visited[nr][nc] = true; 
            }
        }
    }
};

/**
# Ideas:
- At each cell, calculate a "score", which is the minimum score to reach both islands
- Binary Search + Validator

# Approach:
- From each island, BFS to calculate the score from each point to that island

[[0,1,0,0,0],
 [0,1,0,1,1],
 [0,0,0,0,1],
 [0,0,0,0,0],
 [0,0,0,0,0]]


**/
