/*
 * 827. Making A Large Island
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 1960 ms (beats 5.0%)
 * Memory: 83.4 MB (beats 97.5%)
 * Submitted: 2026-03-15 15:59:05 UTC
 * URL: https://leetcode.com/submissions/detail/1949245029/
 */

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dirs = {{1,0}, {0,1}, {-1,0}, {0, -1}};
        unordered_map<int, int> island2Size;
        int islandId = 2;

        // phase 1: explore existing islands
        for(int r = 0; r < n; ++r) {
            for(int c = 0; c < n; ++c) {
                if(grid[r][c] == 1) {
                    grid[r][c] = islandId;
                    island2Size[islandId]++;
                    explore(grid, dirs, island2Size, n, islandId, r, c);

                    islandId++;
                }
            }
        }


        // phase 2: connecting islands, and calculate the res
        int res = 0;
        for(auto it = island2Size.begin(); it != island2Size.end(); ++it) {
            res = max(res, it->second);
        }

        unordered_set<int> connected;
        for(int r = 0; r < n; ++r) {
            for(int c = 0; c < n; ++c) {
                if(grid[r][c] != 0) continue;

                for(auto& dir : dirs) {
                    int nr = r + dir[0], nc = c + dir[1];
                    if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                    if(grid[nr][nc] == 0) continue;
                    connected.insert(grid[nr][nc]);
                }

                int size = 1;
                for(auto it = connected.begin(); it != connected.end(); ++it) {
                    size += island2Size[*it];
                }
                res = max(res, size);

                connected.clear();
            }
        }

        return res;
    }

    void explore(vector<vector<int>> &grid, vector<vector<int>>& dirs, unordered_map<int, int>& island2Size, int n, int id, int r, int c) {
        cout << "r: " << r << ", c: " << c << endl;
        for(auto& dir : dirs) {
            int nr = r + dir[0], nc = c + dir[1];

            if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
            if(grid[nr][nc] != 1) continue;

            grid[nr][nc] = id;
            island2Size[id]++;
            explore(grid, dirs, island2Size, n, id, nr, nc);
        }
    }
};

/**
Approach:
- Phase 1: explore the islands
    - mark the island by its id
    - map[id: size]

- Phase 2: go through the grid
    - if sees a zero:
        - turn to 1
        
        connected_set
        - explore 4 directions:
            if dir != 0: connected_set << dir
        
        size = 1
        for each item in set:
            size += map[item]
        
        res = max(res, size)

TC: O(n x n)
SC: O(number of islands)
        
**/
