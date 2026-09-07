/*
 * 864. Shortest Path to Get All Keys
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 1414 ms (beats 5.1%)
 * Memory: 42.1 MB (beats 13.2%)
 * Submitted: 2026-03-16 16:25:24 UTC
 * URL: https://leetcode.com/submissions/detail/1950251325/
 */

class Solution {
  public:
    int shortestPathAllKeys(vector<string> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        int startR = -1, startC = -1, keys = 0;
        for(int r = 0; r < m; ++r) {
            for(int c = 0; c < n; ++c) {
                if(grid[r][c] == '@') {
                    startR = r;
                    startC = c;
                } else if(isKey(grid[r][c])) keys++;
            }
        }

        queue<vector<int>> q;
        unordered_set<string> visited;
        q.push({startR, startC, 0, 0});
        visited.insert(serialize(startR, startC, 0));

        while(!q.empty()) {
            auto& top = q.front();
            int r = top[0], c = top[1], k = top[2], dist = top[3];
            q.pop();

            cout << "r: " << r << ", c: " << c << ", k: " << k << endl;
            if(k == pow(2, keys) - 1) return dist;

            for(auto& dir : dirs) {
                int nr = r + dir[0], nc = c + dir[1], nk = k;

                if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if(isWall(grid[nr][nc])) continue;
                if(isLock(grid[nr][nc])) {
                    char lock = grid[nr][nc];
                    bool haveKey = k & (1 << (lock - 'A')); 
                    if(!haveKey) continue; 
                }
                if(isKey(grid[nr][nc])) {
                    char key = grid[nr][nc];
                    nk = k | (1 << (key - 'a'));
                }
                if(visited.count(serialize(nr, nc, nk))) continue;
                
                q.push({nr, nc, nk, dist + 1});
                visited.insert(serialize(nr, nc, nk));
            }
        }

        return -1;
    };

    string serialize(int r, int c, int k) {
        return to_string(r) + "." + to_string(c) + "." + to_string(k); 
    }

    bool isKey(char c) {
        return isalpha(c) && islower(c);
    }
    bool isLock(char c) {
        return isalpha(c) && isupper(c);
    }
    bool isWall(char c) {
        return c == '#';
    }
};

/**
# Thoughts:
- What state?
    - current position
    - which keys
- How many state?
    m * n * 2^k = 30 * 30 * 64 << 10^7
=> DFS/BFS

# Approach:
- BFS until getting all keys
**/
