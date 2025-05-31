#include <iostream>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  unordered_set<int> cols;
  unordered_set<int> posDiags;
  unordered_set<int> negDiags;
  int N;

  int totalNQueens(int n) {
    int res = 0;
    N = n;

    for (int c = 0; c < N; ++c) {
      res += dfs(0, c);
    }

    return res;
  }

private:
  bool isValid(int r, int c) {
    if (cols.find(c) != cols.end()) return false;
    if (posDiags.find(r + c) != posDiags.end()) return false;
    if (negDiags.find(r - c) != negDiags.end()) return false;
    return true;
  }

  int dfs(int r, int c) {
    if (r >= N - 1) {
      return 1;
    }

    cols.insert(c);
    posDiags.insert(r + c);
    negDiags.insert(r - c);

    int res = 0;
    for (int nextC = 0; nextC < N; nextC++) {
      if (isValid(r + 1, nextC)) {
        res += dfs(r + 1, nextC);
      }
    }

    cols.erase(c);
    posDiags.erase(r + c);
    negDiags.erase(r - c);

    return res;
  }
};
