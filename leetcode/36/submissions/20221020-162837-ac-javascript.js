/*
 * 36. Valid Sudoku
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 107 ms (beats 5.2%)
 * Memory: 45.5 MB (beats 100.0%)
 * Submitted: 2022-10-20 16:28:37 UTC
 * URL: https://leetcode.com/submissions/detail/826720300/
 */

/**
 * @param {character[][]} board
 * @return {boolean}
 */


/***
[0,0] [0,1] [0,2]  |  [0,3] [0,4] [0,5]
[1,0] [1,1] [1,2]  |  ...         ...
[2,0] [2,1] [2,2]  |  ...   ...   [2,5]

***/
var isValidSudoku = function(board) {
    const n = board.length;
    
    let rows = [];
    let cols = [];
    let boxes = [];
    
        
    for(let i = 0; i < board.length; i++){
        rows.push(new Set());
        cols.push(new Set());
        boxes.push(new Set());
    }
    
    
    let curr_val = 0;
    for(let i = 0; i < n; i++){
        for(let j = 0; j < n; j++){
            curr_val = board[i][j];
            
            if(curr_val === ".") continue;
            
            // Check if row already has this value
            if(rows[i].has(curr_val)) return false;
            else rows[i].add(curr_val);
            
            // Check if col already has this value
            if(cols[j].has(curr_val)) return false;
            else cols[j].add(curr_val);
            
            // Check if current box has this value
            let boxIndex = Math.floor((i / 3)) * 3 + Math.floor(j / 3);
            if(boxes[boxIndex].has(curr_val)) return false;
            else boxes[boxIndex].add(curr_val);
        }
    }
    
    return true;
};
