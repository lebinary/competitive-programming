/*
 * 1102. Path With Maximum Minimum Value
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 217 ms (beats 33.1%)
 * Memory: 70.9 MB (beats 37.2%)
 * Submitted: 2026-03-03 13:35:43 UTC
 * URL: https://leetcode.com/submissions/detail/1936750692/
 */

class Solution {
public: 
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        int l = INT_MAX, r = INT_MIN;

        for(int i = 0; i < R; ++i) {
            for(int j = 0; j < C; ++j) {
                l = min(l, grid[i][j]);
                r = max(r, grid[i][j]);
            }
        }

        while(l < r) {
            int m = l + (r - l + 1) / 2;
            if(validator(grid, dirs, R, C, m)) l = m;
            else r = m - 1;
        }

        return l;
    }

    bool validator(vector<vector<int>>& grid, vector<vector<int>> &dirs, int R, int C, int score) {
        if(grid[0][0] < score) return false;

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        q.push({0, 0});
        visited[0][0] = true;

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if(r == R - 1 && c == C - 1) return true;

            for(vector<int> &dir : dirs) {
                int nr = r + dir[0], nc = c + dir[1];

                if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue; 
                if(visited[nr][nc]) continue;
                if(grid[nr][nc] < score) continue; 

                q.push({nr, nc});
                visited[nr][nc] = true;
            }
        }

        return false;
    }
};

/**
approach:
- BS on the score
- BFS validator
=> O(logV M*N)


[[0,1,0,0,0,1],
 [0,1,1,0,0,0],
 [0,0,1,1,0,1],
 [0,1,1,1,1,0],
 [1,1,1,1,1,1]]
**/
