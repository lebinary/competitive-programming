/*
 * 48. Rotate Image
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 10.3 MB (beats 9.1%)
 * Submitted: 2025-05-15 14:21:11 UTC
 * URL: https://leetcode.com/submissions/detail/1634718201/
 */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // vertically reverse
        for (int r = 0; r < n/2; ++r){
            int lastR = n - r - 1;

            for(int c = 0; c < n; ++c){
                swap(matrix[r][c], matrix[lastR][c]);       
            } 
        }

        // transpose
        for (int r = 0; r < n-1; ++r){
            for (int c = r+1; c < n; ++ c) {
                swap(matrix[r][c], matrix[c][r]);
            }
        }
    }
};
