#include <algorithm>
#include <cctype>
#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();

        // vertically inverse
        for (int r = 0; r < n / 2; ++r) {
            for (int c = 0; c < n; ++c) {
                swap(matrix[r][c], matrix[n - r - 1][c]);
            }
        }

        // transpose
        for (int r = 0; r < n; ++r) {
            for (int c = r + 1; c < n; ++c) {
                swap(matrix[r][c], matrix[c][r]);
            }
        }
    }
};
