/*
 * 200. Number of Islands
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 25 ms (beats 71.6%)
 * Memory: 16.4 MB (beats 70.4%)
 * Submitted: 2026-03-10 13:19:42 UTC
 * URL: https://leetcode.com/submissions/detail/1943943849/
 */

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int island = 0;

        for(int r = 0; r < m; ++r) {
            for(int c = 0; c < n; ++c) {
                if(grid[r][c] == '1') {
                    explore(grid, m, n, r, c);
                    island++;
                }
            }
        }

        return island;
    }

    void explore(vector<vector<char>>& grid, int m, int n, int r, int c) {
        if(r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != '1') return;

        grid[r][c] = '2';
        explore(grid, m, n, r + 1, c);
        explore(grid, m, n, r, c + 1);
        explore(grid, m, n, r - 1, c);
        explore(grid, m, n, r, c - 1);
    }
};

/**
Approach: for each positions in grid, "explore" the island

for r : row:
    for c: col:
        if new island:
            explore
            island++
return island

TC: O(2mn) - each position can be visited at most 2 times, one by traverse, one by explore
SC: O(alpha)
**/
