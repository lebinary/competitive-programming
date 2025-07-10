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
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int i = -1, l = 0, r = m;
        while (l < r) {
            int m = (l + r) / 2;

            if (matrix[m][0] <= target && target <= matrix[m][n - 1]) {
                i = m;
                break;
            } else if (matrix[m][n - 1] < target)
                l = m + 1;
            else
                r = m;
        }

        if (i == -1) return false;

        l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (matrix[i][m] == target)
                return true;
            else if (matrix[i][m] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        return false;
    }
};
