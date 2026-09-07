/*
 * 490. The Maze
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 81 ms (beats 5.2%)
 * Memory: 56.7 MB (beats 5.2%)
 * Submitted: 2026-03-20 14:55:51 UTC
 * URL: https://leetcode.com/submissions/detail/1954012685/
 */

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dirs = {{-1,0}, {0, 1}, {1, 0}, {0, -1}};
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(4, -1)));
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(4, false)));
        
        bool res = false;
        for(int d = 0; d < 4; ++d) {
            int r = start[0], c = start[1];
            res = res || dfs(maze, dp, visited, dirs, destination, m, n, r, c, d);
        }

        return res;
    }

    bool dfs(vector<vector<int>>& maze, vector<vector<vector<int>>>& dp, vector<vector<vector<bool>>>& visited, vector<vector<int>>& dirs, vector<int>& destination, int m, int n, int r, int c, int d) {
        if(r < 0 || r >= m || c < 0 || c >= n) return false;
        if(dp[r][c][d] != -1) return dp[r][c][d];
        if(maze[r][c] == 1) return dp[r][c][d] = false;
        if(visited[r][c][d]) return dp[r][c][d] = false;
        visited[r][c][d] = true;

        bool res = false;
        int nr = r + dirs[d][0], nc = c + dirs[d][1];
        if(nr < 0 || nr >= m || nc < 0 || nc >= n || maze[nr][nc]) {
            if(r == destination[0] && c == destination[1]) return dp[r][c][d] = true;

            for(int i = 1; i < 4; ++i) {
                int nd = (d + i) % 4;
                res = res || dfs(maze, dp, visited, dirs, destination, m, n, r, c, nd);
            }
        } else {
            res = dfs(maze, dp, visited, dirs, destination, m, n, nr, nc, d);
        }

        return dp[r][c][d] = res;
    }
};
/**
What state to track?
- The position of the ball: m * n = 100 * 100
- The direction of the ball: d = 4
=> Total states: 100 * 100 * 4 = 40000 < 10^7
=> DP with 3 dimensions

## Approach:
- dfs(pos, dir):
    if pos is wall: return false
    if dp[pos][dir] exist: return dp[pos][dir]

    if pos + dir is wall: 
        if pos is dest: return true

        for all other directions:
            res = res || dfs(pos, otherDir)
    else: 
        res = dfs(pos, dir)

    return res
**/
