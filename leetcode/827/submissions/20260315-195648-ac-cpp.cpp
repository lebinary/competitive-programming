/*
 * 827. Making A Large Island
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 189 ms (beats 58.8%)
 * Memory: 91.6 MB (beats 96.0%)
 * Submitted: 2026-03-15 19:56:48 UTC
 * URL: https://leetcode.com/submissions/detail/1949460568/
 */

class DSU {
    public:
        vector<int> parent;
        vector<int> size;
        int numSets;
    
        DSU(int n) {
            this->parent.assign(n, 0);
            this->size.assign(n, 1);
            this->numSets = n;

            for(int i = 0; i < n; ++i) {
                this->parent[i] = i;
            }
        }

        int find(int node) {
            if(parent[node] != node) parent[node] = find(parent[node]);
            return parent[node];
        }

        bool unionNodes(int nodeA, int nodeB) {
            int parentA = find(nodeA), parentB = find(nodeB);
            if(parentA == parentB) return false;
            if(size[parentA] < size[parentB]) swap(parentA, parentB);

            numSets--;
            size[parentA] += size[parentB];
            parent[parentB] = parentA;
            
            return true;
        }

        int getSize(int node) {
            int parentNode = find(node);
            return size[parentNode];
        }

        int components() {
            return numSets;
        }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dirs = {{1,0}, {0,1}, {-1,0}, {0, -1}};
        DSU islands(n * n);

        // phase 1: explore existing islands
        for(int r = 0; r < n; ++r) {
            for(int c = 0; c < n; ++c) {
                if(grid[r][c] == 1) {
                    int currNode = r * n + c;

                    for(auto& dir : dirs) {
                        int nr = r + dir[0], nc = c + dir[1];
                        
                        if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                        if(grid[nr][nc] == 0) continue;
                        
                        int neiNode = nr * n + nc;
                        islands.unionNodes(currNode, neiNode);
                    }
                }
            }
        }


        // phase 2: connecting islands, and calculate the res
        int res = 0;
        unordered_set<int> uniqIslands;

        for(int r = 0; r < n; ++r) {
            for(int c = 0; c < n; ++c) {
                if(grid[r][c] == 0) {
                    for(auto& dir : dirs) {
                        int nr = r + dir[0], nc = c + dir[1];
                        
                        if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                        if(grid[nr][nc] == 0) continue;
                        
                        int node = nr * n + nc;
                        uniqIslands.insert(islands.find(node));
                    }

                    int cumSize = 1; 
                    for(auto it = uniqIslands.begin(); it != uniqIslands.end(); ++it) {
                        cumSize += islands.getSize(*it);
                    }
                    res = max(res, cumSize);
                    
                    uniqIslands.clear();
                } else {
                    int node = r * n + c;
                    res = max(res, islands.getSize(node));
                }
            }
        }

        return res;
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
