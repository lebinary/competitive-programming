/*
 * 79. Word Search
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 478 ms (beats 34.9%)
 * Memory: 11.6 MB (beats 37.2%)
 * Submitted: 2026-03-28 15:14:28 UTC
 * URL: https://leetcode.com/submissions/detail/1961903848/
 */

class Solution {
    int m, n;
    vector<vector<bool>> visited;
    const int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  public:
    bool exist(vector<vector<char>> &board, string word) {
        this->m = board.size(), this->n = board[0].size();
        this->visited.assign(m, vector<bool>(n, false));

        for(int r = 0; r < m; ++r) {
            for(int c = 0; c < n; ++c) {
                if(search(board, word, r, c, 0)) return true;
            }
        }
        return false;
    }

    bool search(auto& board, string& word, int r, int c, int i) {
        if(i >= word.size()) return true;
        if(r < 0 || r >= m || c < 0 || c >= n) return false;
        if(visited[r][c]) return false;
        if(board[r][c] != word[i]) return false;

        visited[r][c] = true;
        for(auto& dir : dirs) {
            int nr = r + dir[0], nc = c + dir[1];    
            if(search(board, word, nr, nc, i + 1)) return true;
        }
        visited[r][c] = false;

        return false;
    }
};

/**
Approach: DFS for each valid starting point

dfs(r, c, i):
    if i reach the end of word: ret true
    if r, c out of range: ret false
    if r, c have visited: ret false
    if board[r, c] != word[i]: ret false

    try all neighboring directions:
        if any return true: return true

    return false 
**/
