/*
 * 286. Walls and Gates
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 72 ms (beats 10.1%)
 * Memory: 36.4 MB (beats 9.5%)
 * Submitted: 2025-12-14 11:38:03 UTC
 * URL: https://leetcode.com/submissions/detail/1855331776/
 */

class Solution {
  public:
    void wallsAndGates(vector<vector<int>> &rooms) {
        int R = rooms.size(), C = rooms[0].size(), INF = pow(2, 31) - 1;
        vector<vector<int>> DIRS = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        queue<vector<int>> q;

        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (rooms[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        while (!q.empty()) {
            int n = q.size();

            for (int i = 0; i < n; ++i) {
                vector<int> itm = q.front();
                int r = itm[0], c = itm[1];
                q.pop();

                for (vector<int> dir : DIRS) {
                    int nr = r + dir[0], nc = c + dir[1];
                    if (nr < 0 || nr >= R || nc < 0 || nc >= C || rooms[nr][nc] == -1 || rooms[nr][nc] != INF) continue;
                    q.push({nr, nc});
                    rooms[nr][nc] = rooms[r][c] + 1;
                }
            }
        }
    }
};
