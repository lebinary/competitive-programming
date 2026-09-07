/*
 * 348. Design Tic-Tac-Toe
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 20 ms (beats 62.5%)
 * Memory: 26.4 MB (beats 35.1%)
 * Submitted: 2026-03-29 12:45:01 UTC
 * URL: https://leetcode.com/submissions/detail/1962847156/
 */

 class TicTacToe {
    int n;
    vector<vector<int>> rows;
    vector<vector<int>> cols;
    vector<vector<int>> diags;

public:
    TicTacToe(int n) {
        this->n = n;
        this->rows.assign(n, vector<int>(3, 0));
        this->cols.assign(n, vector<int>(3, 0));
        this->diags.assign(2, vector<int>(3, 0));
    }
    
    int move(int row, int col, int player) {
        // State 2: Win
        rows[row][player] = 1;
        rows[row][0]++;
        if(rows[row][0] == n && rows[row][1] + rows[row][2] == 1) {
            cout << "row: " << row << ", col: " << col << endl;
            return rows[row][1] ? 1 : 2;
        }

        cols[col][player] = 1;
        cols[col][0]++;
        if(cols[col][0] == n && cols[col][1] + cols[col][2] == 1) {
            return cols[col][1] ? 1 : 2;
        }

        if(row == col) {
            diags[0][player] = 1;
            diags[0][0]++;
            if(diags[0][0] == n && diags[0][1] + diags[0][2] == 1) {
                return diags[0][1] ? 1 : 2;
            }
        }

        if(row + col == n - 1) {
            diags[1][player] = 1;
            diags[1][0]++;
            if(diags[1][0] == n && diags[1][1] + diags[1][2] == 1) {
                return diags[1][1] ? 1 : 2;
            }
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

**/

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
