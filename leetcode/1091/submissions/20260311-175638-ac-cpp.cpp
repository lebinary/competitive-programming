/*
 * 1091. Shortest Path in Binary Matrix
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 58 ms (beats 13.1%)
 * Memory: 35.6 MB (beats 12.8%)
 * Submitted: 2026-03-11 17:56:39 UTC
 * URL: https://leetcode.com/submissions/detail/1945306330/
 */

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        
        int n = grid.size();
        vector<vector<int>> dirs = {{1,0}, {0,1}, {-1,0}, {0, -1}, {-1,1}, {1,-1}, {-1,-1}, {1, 1}};
        queue<vector<int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        q.push({0, 0, 1});
        visited[0][0] = true;

        while(!q.empty()) {
            vector<int>& item = q.front();
            int r = item[0], c = item[1], dist = item[2];
            q.pop();

            if(r == n - 1 && c == n - 1) return dist;

            for(const vector<int> &dir : dirs) {
                int nr = r + dir[0], nc = c + dir[1];

                if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                if(visited[nr][nc]) continue;
                if(grid[nr][nc] == 1) continue;
                
                q.push({nr, nc, dist + 1});
                visited[nr][nc] = true;
            }
        }

        return -1;
    }
};

/**
# Ideas: 
- Shortest path + weight = 1 => BFS
- 8 directions

# Approach:
- BFS with 8 dirs
- If ever each grid[n-1][n-1], return  
**/
