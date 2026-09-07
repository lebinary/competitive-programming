/*
 * 74. Search a 2D Matrix
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 99 ms (beats 2.7%)
 * Memory: 42.2 MB (beats 100.0%)
 * Submitted: 2022-08-14 19:16:57 UTC
 * URL: https://leetcode.com/submissions/detail/773705053/
 */

/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
    const rows = matrix.length;
    const cols = matrix[0].length;
    
    let top = 0;
    let bot = rows - 1;
    let cur_row = Math.floor((top + bot) /2);
    
    while(top <= bot){
        cur_row = Math.floor((top + bot) /2);
        
        if(target > matrix[cur_row][cols-1]){
            top = cur_row + 1;
        }else if(target < matrix[cur_row][0]){
            bot = cur_row - 1;
        }else{
            break;
        }
    }
    
    if(top > bot) return false;
    
    let left = 0;
    let right = cols - 1;
    while(left <= right){
        let mid = Math.floor((left + right) /2);
        if(target > matrix[cur_row][mid]){
            left = mid + 1;
        }else if(target < matrix[cur_row][mid]){
            right = mid - 1;
        }else{
            return true;
        }
    }
    
    return false;
};
