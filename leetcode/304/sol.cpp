#include <algorithm>
#include <cctype>
#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class NumMatrix {
  public:
    vector<vector<int>> prefix;
    int m, n;
    NumMatrix(vector<vector<int>> &matrix) {
        this->m = matrix.size(), this->n = matrix[0].size();
        this->prefix.assign(m, vector<int>(n, 0));

        for (int r = 0; r < m; ++r) {
            int sum = 0;
            for (int c = 0; c < n; ++c) {
                sum += matrix[r][c];
                prefix[r][c] += sum;
                if (r > 0) prefix[r][c] += prefix[r - 1][c];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int bottomLeft = col1 == 0 ? 0 : prefix[row2][col1 - 1];
        int topRight = row1 == 0 ? 0 : prefix[row1 - 1][col2];
        int topLeft = row1 == 0 || col1 == 0 ? 0 : prefix[row1 - 1][col1 - 1];
        return prefix[row2][col2] - bottomLeft - topRight + topLeft;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
