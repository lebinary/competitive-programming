#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int r = 0, c = 0, currDir = 0;
    vector<int> res;

    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while (res.size() < m * n) {
      res.push_back(matrix[r][c]);
      matrix[r][c] = 111; // mark visited

      int nextR = r + dir[currDir][0];
      int nextC = c + dir[currDir][1];

      if (nextR >= m || nextR < 0 || nextC >= n || nextC < 0 || matrix[nextR][nextC] == 111) {
        currDir = (currDir + 1) % 4;
      }

      r += dir[currDir][0];
      c += dir[currDir][1];
    }

    return res;
  };
};
