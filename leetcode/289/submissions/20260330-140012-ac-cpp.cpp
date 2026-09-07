/*
 * 289. Game of Life
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 9.7 MB (beats 31.4%)
 * Submitted: 2026-03-30 14:00:12 UTC
 * URL: https://leetcode.com/submissions/detail/1963882736/
 */

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> dirs = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

        for(int r = 0; r < m; ++r) {
            for(int c = 0; c < n; ++c) {
                int liveCount = 0;
                for(auto& dir : dirs) {
                    int nr = r + dir[0], nc = c + dir[1];
                    if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if(isLive(board[nr][nc])) liveCount++;
                }

                if(isLive(board[r][c]) && (liveCount < 2 || liveCount > 3)) {
                    board[r][c] = 3;
                } 
                
                if(!isLive(board[r][c]) && liveCount == 3) {
                    board[r][c] = 2;
                }
            }
        }

        for(int r = 0; r < m; ++r) {
            for(int c = 0; c < n; ++c) {
                if(board[r][c] == 3) board[r][c] = 0;
                if(board[r][c] == 2) board[r][c] = 1;
            }
        }
    }

    bool isLive(int val) {
        if(val == 1 || val == 3) return true;
        return false;
    }
};

/**
# Approach 1: Create an alternative board
TC: O(m * n)
SC: O(m * n)

# Appraoch 2:  
- Record the transitions:
    0 -> 1  => 2, prev = 2 - 2 = 0 
    1 -> 0  => 3, prev = 3 - 2 = 1
- So: value is 
    0, 1 => take as is
    2, 3 => get prev value
- Second pass, convert:
    2 -> 1
    3 -> 0
**/
