/*
 * 499. The Maze III
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 17.9 MB (beats 10.5%)
 * Submitted: 2026-04-07 13:32:17 UTC
 * URL: https://leetcode.com/submissions/detail/1971590307/
 */

// BFS with priority
class Solution {
    vector<vector<int>> dirs = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}}; // order lexicography
    vector<string> dirStr = {"d", "l", "r", "u"};
    unordered_map<char, int> dirIdx = {{'d', 0}, {'l', 1}, {'r', 2}, {'u', 3}}; 

public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int m = maze.size(), n = maze[0].size();

        queue<tuple<int, int, string, int>> q;
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(4, false)));

        q.push({ball[0], ball[1], "*", 0});
        for(int d = 0; d < 4; ++d) {
            visited[ball[0]][ball[1]][d] = true;
        }

        while(!q.empty()) {
            auto [r, c, path, dist] = q.front();
            q.pop();

            if(r == hole[0] && c == hole[1]) return path.substr(1);

            // initial position
            if(path.back() == '*') {
                for(int d = 0; d < 4; ++d) {
                    int nr = ball[0] + dirs[d][0], nc = ball[1] + dirs[d][1];

                    if(nr < 0 || nr >= m || nc < 0 || nc >= n || maze[nr][nc] == 1) continue;
                    if(visited[nr][nc][d]) continue;

                    string newPath = path + dirStr[d]; 
                    q.push({nr, nc, newPath, dist + 1});
                    visited[nr][nc][d] = true;
                }
                
                continue;
            }
            
            int d = dirIdx[path.back()];
            int nr = r + dirs[d][0];
            int nc = c + dirs[d][1];
            
            // can move forward
            if(nr >= 0 && nr < m && nc >= 0 && nc < n && maze[nr][nc] != 1) {
                if(visited[nr][nc][d] == true) continue;
             
                q.push({nr, nc, path, dist + 1});
                visited[nr][nc][d] = true;
                continue;
            }

            // cant move forward, try other directions
            for(int nd = 0; nd < 4; ++nd) {
                nr = r + dirs[nd][0], nc = c + dirs[nd][1];

                if(nr < 0 || nr >= m || nc < 0 || nc >= n || maze[nr][nc] == 1) continue;
                if(visited[nr][nc][nd]) continue;

                string newPath = path + dirStr[nd];
                q.push({nr, nc, newPath, dist + 1});
                visited[nr][nc][nd] = true;
            }
        }

        return "impossible";
    }
};

/**
What state to store? How many?
- position of the ball => m * n
- direction of the ball => 4
=> Total states: m * n * 4 << 10^7

"Shortest distance" => BFS

Main challenge: how to capture the best path
- push order matters, need to push in lexicographical order
**/
