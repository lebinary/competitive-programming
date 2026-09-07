/*
 * 529. Minesweeper
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 16.1 MB (beats 30.5%)
 * Submitted: 2026-03-28 11:07:29 UTC
 * URL: https://leetcode.com/submissions/detail/1961675711/
 */

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }

        int m = board.size(), n = board[0].size();
        vector<vector<int>> dirs = {{-1, 0}, {-1,1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
        
        queue<pair<int, int>> q;
        q.push({click[0], click[1]});
        board[click[0]][click[1]] = 'B';

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if(board[r][c] == 'M') {
                board[r][c] = 'X';
                return board;
            }

            int mineCount = 0;
            for(auto& dir : dirs) {
                int nr = r + dir[0], nc = c + dir[1];

                if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if(board[nr][nc] == 'M') mineCount++;
            }

            if(mineCount > 0) {
                board[r][c] = mineCount + '0';
                continue;
            }
            
            for(auto& dir: dirs) {
                int nr = r + dir[0], nc = c + dir[1];

                if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if(board[nr][nc] != 'E') continue;

                q.push({nr, nc});
                board[nr][nc] = 'B';
            }
        }

        return board;
    }
};

/**
Revealed:
M -> X -> game over
E -> B -> recursively reveal
    - if while recursive, see an adjacent 
        update square
        stop recurse 

What state? How many?
- current position

# Approach:
- BFS, for each position
    check adjacent, if countMine == 0:
        update 'B'
        continue traverse
    else:
        update to countMine
        stop traverse
        
**/
