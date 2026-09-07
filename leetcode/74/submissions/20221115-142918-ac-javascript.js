/*
 * 74. Search a 2D Matrix
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 94 ms (beats 2.7%)
 * Memory: 41.8 MB (beats 100.0%)
 * Submitted: 2022-11-15 14:29:18 UTC
 * URL: https://leetcode.com/submissions/detail/843936097/
 */

/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
    let [rows, cols] = [matrix.length, matrix[0].length];
    let [top, bot] = [0, rows - 1];

    while(top <= bot){
        let row = Math.floor((bot + top) / 2);
        if(target < matrix[row][0]) bot = row - 1;
        else if(target > matrix[row][cols - 1]) top = row + 1;
        else break;
    }
    if(!(top <= bot)) return false;

    let row = Math.floor((bot + top) / 2);
    let [left, right] = [0, cols - 1];
    while(left <= right){
        let mid = Math.floor((left + right) / 2);
        if(target > matrix[row][mid]) left = mid + 1;
        else if(target < matrix[row][mid]) right = mid - 1;
        else if(matrix[row][mid] === target) return true;
    }

    return false;
};

/** Another way to solve this, turn 2D array into 1D array, then do binary search */
