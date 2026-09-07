/*
 * 773. Sliding Puzzle
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 11 ms (beats 35.7%)
 * Memory: 12.2 MB (beats 33.1%)
 * Submitted: 2026-03-18 08:39:49 UTC
 * URL: https://leetcode.com/submissions/detail/1951921337/
 */

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        queue<string> q;
        unordered_set<string> visited;

        string state = serialize(board);
        q.push(state);
        visited.insert(state);

        int dist = 0;
        vector<vector<int>> currBoard = board;

        while(!q.empty()) {
            int n = q.size();

            for(int i = 0; i < n; ++i) {
                state = q.front();
                q.pop();

                currBoard = deserialize(state);                
                if(isValid(currBoard)) return dist;

                int zeroR = -1, zeroC = -1;
                for(int r = 0; r < 2; ++r) {
                    for(int c = 0; c < 3; ++c) {
                        if(currBoard[r][c] == 0) {
                            zeroR = r; zeroC = c;
                            break;
                        }
                    }
                }

                for(auto& dir : dirs) {
                    int nr = zeroR + dir[0], nc = zeroC + dir[1];
                    if(nr < 0 || nr >= 2 || nc < 0 || nc >= 3) continue;

                    swap(currBoard[zeroR][zeroC], currBoard[nr][nc]);

                    string newState = serialize(currBoard);
                    if(!visited.count(newState)) {
                        q.push(newState);
                        visited.insert(newState);
                    };

                    swap(currBoard[zeroR][zeroC], currBoard[nr][nc]);
                }
            }

            dist++;
        }

        return -1;
    }

    bool isValid(vector<vector<int>>& board) {
        if(board[1][2] != 0) return false;
        for(int r = 0; r < 2; ++r) {
            for(int c = 0; c < 3; ++c) {
                if(r == 1 && c == 2) continue;
                if(board[r][c] != r * 3 + c + 1) return false;
            }
        }
        return true;
    }

    string serialize(vector<vector<int>>& board) {
        string encoded = "";
        for(int r = 0; r < 2; ++r) {
            for(int c = 0; c < 3; ++c) {
                encoded += (board[r][c] + '0');
            }
        }
        return encoded;
    }

    vector<vector<int>> deserialize(string encoded) {
        vector<vector<int>> decoded(2, vector<int>(3, -1));
        for(int r = 0; r < 2; ++r) {
            for(int c = 0; c < 3; ++c) {
                decoded[r][c] = encoded[r * 3 + c] - '0';
            }
        } 
        return decoded;
    }
};

/**
What are the states? And how many?
- Board state: 6! = 720 << 10^7

# Approach: BFS
- BFS the state of the board
    - Once 0-index lands in bottom right, check if the state is valid
- Once checked all the the states and still no valid, return -1
**/
