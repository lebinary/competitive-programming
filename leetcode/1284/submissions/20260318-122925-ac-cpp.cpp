/*
 * 1284. Minimum Number of Flips to Convert Binary Matrix to Zero Matrix
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 4 ms (beats 29.3%)
 * Memory: 11.5 MB (beats 27.6%)
 * Submitted: 2026-03-18 12:29:25 UTC
 * URL: https://leetcode.com/submissions/detail/1952081264/
 */

class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        queue<string> q;
        unordered_set<string> visited;
        
        string state = serialize(mat, m, n); 
        q.push(state);
        visited.insert(state);

        int steps = 0;
        vector<vector<int>> currMat = mat;
        while(!q.empty()) {
            int qSize = q.size();

            for(int i = 0; i < qSize; ++i) {
                state = q.front();
                q.pop();

                currMat = deserialize(state, m, n);
                if(isValid(currMat, m, n)) return steps;

                for(int r = 0; r < m; ++r) {
                    for(int c = 0; c < n; ++c) {
                        // flip
                        flip(currMat, dirs, m, n, r, c);

                        string newState = serialize(currMat, m, n);
                        if(!visited.count(newState)) {
                            q.push(newState);
                            visited.insert(newState);
                        }

                        // unflip
                        flip(currMat, dirs, m, n, r, c);
                    }
                }
            }

            steps++;
        }
        return -1;
    }

    string serialize(vector<vector<int>>& mat, int m, int n) {
        string enc(m * n, '0');
        for(int r = 0; r < m; ++r) {
            for(int c = 0; c < n; ++c) {
                enc[r * n + c] = (mat[r][c] + '0');
            }
        }
        return enc;
    }

    vector<vector<int>> deserialize(string s, int m, int n) {
        vector<vector<int>> dec(m, vector<int>(n, -1));
        for(int r = 0; r < m; ++r) {
            for(int c = 0; c < n; ++c) dec[r][c] = s[r * n + c] - '0';
        }
        return dec;
    }

    bool isValid(vector<vector<int>>& mat, int m, int n) {
        for(int r = 0; r < m; ++r) {
            for(int c = 0; c < n; ++c) if(mat[r][c] != 0) return false;
        }
        return true;
    }

    void flip(vector<vector<int>>& mat, vector<vector<int>>& dirs, int m, int n, int flipR, int flipC) {
        mat[flipR][flipC] ^= 1;
        for(auto& dir : dirs) {
            int nr = flipR + dir[0], nc = flipC + dir[1];
            if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
            mat[nr][nc] ^= 1;
        }
    }
};

/**
what state to store? size of the state?
- The matrix: m * n = 3 * 3 = 9 << 10^7

=> "Minimum" == BFS

# Approach: BFS through all the state until reach the valid state (all zeros)
**/
