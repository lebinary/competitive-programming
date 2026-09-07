/*
 * 505. The Maze II
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 63 ms (beats 9.0%)
 * Memory: 43.1 MB (beats 5.3%)
 * Submitted: 2026-04-06 07:20:33 UTC
 * URL: https://leetcode.com/submissions/detail/1970316482/
 */

class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dirs = {{-1,0}, {0,1}, {1, 0}, {0, -1}};
        vector<vector<vector<int>>> visited(m, vector<vector<int>>(n, vector<int>(4, false)));

        queue<vector<int>> q;
        for(int d = 0; d < 4; ++d) {
            q.push({start[0], start[1], d, 0});
            visited[start[0]][start[1]][d] = true;
        }

        while(!q.empty()) {
            auto& top = q.front();
            int r = top[0], c = top[1], d = top[2], dist = top[3];
            q.pop();

            int nr = r + dirs[d][0], nc = c + dirs[d][1];
            
            if(nr < 0 || nr >= m || nc < 0 || nc >= n || maze[nr][nc] == 1) {
                if(r == destination[0] && c == destination[1]) return dist;

                for(int i = 0; i < 4; ++i) {
                    int nd = (d + i) % 4;
                    nr = r + dirs[nd][0], nc = c + dirs[nd][1];

                    if(nr < 0 || nr >= m || nc < 0 || nc >= n || maze[nr][nc] == 1) continue;
                    if(visited[nr][nc][nd]) continue;

                    q.push({nr, nc, nd, dist + 1});
                    visited[nr][nc][nd] = true;
                }

            } else if(!visited[nr][nc][d]) {
                q.push({nr, nc, d, dist + 1});
                visited[nr][nc][d] = true;
            }
        }

        return -1;
    }
};

/**
What state? How many?
- current position: m * n
- direction: d
=> Total states: m * n * d = 100 * 100 * 4 = 40000 < 10^7

"Shortest distance" => BFS
# Approach:
- For each position and direction:
    - if position + direction is a wall:
        if position is destination: return dist
        
        for all other directions:
            go into that direction
    - else: continue traverse current direction
return -1
**/
