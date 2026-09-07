/*
 * 36. Valid Sudoku
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 77 ms (beats 5.2%)
 * Memory: 44.6 MB (beats 100.0%)
 * Submitted: 2022-05-17 16:11:01 UTC
 * URL: https://leetcode.com/submissions/detail/701505727/
 */

/**
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function(board) {
    const rows = [];
    const columns = [];
    const boxes = [];
    
    for(let i = 0; i < board.length; i++){
        rows.push(new Set());
        columns.push(new Set());
        boxes.push(new Set());
    }
    
    for(let i = 0; i < board.length; i++){
        for(let j = 0; j < board.length; j++){
            let cell = board[i][j];
            
            if(cell === ".") continue;
            
            let boxIndex = Math.floor((i / 3)) * 3 + Math.floor(j / 3);
            if (rows[i].has(cell) || columns[j].has(cell) || boxes[boxIndex].has(cell)) {
                return false;
            }
            
            rows[i].add(cell);
            columns[j].add(cell);
            boxes[boxIndex].add(cell);
        }
    }
    
    return true;
};
