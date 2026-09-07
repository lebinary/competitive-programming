/*
 * 74. Search a 2D Matrix
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 13.4 MB (beats 44.4%)
 * Submitted: 2026-03-03 13:55:20 UTC
 * URL: https://leetcode.com/submissions/detail/1936767079/
 */

class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int R = matrix.size(), C = matrix[0].size();
        
        int row = -1;
        int l = 0, r = R - 1;
        while(l <= r) {
            int m = l + (r - l) / 2;
            
            if(matrix[m][0] <= target && target <= matrix[m][C - 1]) {
                row = m;
                break;
            } else if(matrix[m][0] > target) r = m - 1;
            else l = m + 1;
        }

        if(row == -1) return false;

        l = 0, r = C - 1;
        while(l <= r) {
            int m = l + (r - l) / 2;
            if(matrix[row][m] == target) return true;
            else if(matrix[row][m] > target) r = m - 1;
            else l = m + 1;
        }

        return false;
    }
};

/**
Approach 1: 
- BS on the row ( find if the value falls in the range [matrix[r][0], matrix[r][-1] )
- BS inside the row itself ( find if the value exists in the row )
**/
