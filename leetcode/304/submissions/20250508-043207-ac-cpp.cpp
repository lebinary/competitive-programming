/*
 * 304. Range Sum Query 2D - Immutable
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 40 ms (beats 14.2%)
 * Memory: 149.1 MB (beats 59.0%)
 * Submitted: 2025-05-08 04:32:08 UTC
 * URL: https://leetcode.com/submissions/detail/1628296704/
 */

class NumMatrix {
public:
    vector<vector<int>> prefixSum;

    NumMatrix(vector<vector<int>>& matrix) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        prefixSum = vector<vector<int>>(ROWS+1, vector<int>(COLS+1, 0));

        for (int i = 0; i < matrix.size(); i++) {
            int prefix = 0;
            for (int j = 0; j < matrix[0].size(); j++) {
                prefix += matrix[i][j];
                prefixSum[i+1][j+1] = prefix + prefixSum[i][j+1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int bottomRight = prefixSum[row2+1][col2+1];
        int topRight = prefixSum[row1][col2+1];
        int bottomLeft = prefixSum[row2+1][col1];
        int topLeft = prefixSum[row1][col1];

        return bottomRight - topRight - bottomLeft + topLeft;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
