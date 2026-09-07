/*
 * 348. Design Tic-Tac-Toe
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 15 ms (beats 89.4%)
 * Memory: 26.4 MB (beats 14.8%)
 * Submitted: 2026-03-29 13:00:56 UTC
 * URL: https://leetcode.com/submissions/detail/1962859349/
 */

 class TicTacToe {
    int n;
    vector<int> rows;
    vector<int> cols;
    vector<int> diags;

public:
    TicTacToe(int n) {
        this->n = n;
        this->rows.assign(n, 0);
        this->cols.assign(n, 0);
        this->diags.assign(2, 0);
    }
    
    int move(int row, int col, int player) {
        int op = player == 1 ? 1 : -1;

        rows[row] += op;
        cols[col] += op;
        if(row == col) diags[0] += op;
        if(row + col == n - 1) diags[1] += op;

        if(abs(rows[row]) == n || abs(cols[col]) == n || abs(diags[0]) == n || abs(diags[1]) == n ) {
            return player;
        }

        return 0;
    }
};
/**
State 0; 
- 2 diags have both X and O
- all rows and cols have both X and O

State 2;
- any diags have ONLY X or O
- any row or col have ONLY X or O

State 1:
- the res

What state to track?
- For each row: which player presents, # of space occupied
- For each col: which player presnets, # of space occupied
- 2 Diags: which player presents, # of space occupied

TC: O(1)
SC: O(n^2)

# Approach:
+1 if player1
-1 if player2
check if any count reach n

**/

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
