#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Thansk Larry https://www.youtube.com/watch?v=k6hhIhQmgtQ&t=379s
class Solution {
public:
  string s;
  vector<string> dp1;
  vector<vector<int>> dp2;

  string lexicographicallySmallestString(string s) {
    int n = s.size();
    this->s = s;
    this->dp1.assign(n, "Z");
    this->dp2.assign(n, vector<int>(n, -1));

    return go(0);
  }

  bool isGood(char a, char b) { return abs(a - b) % 24 == 1; }

  bool canRemove(int l, int r) {
    if (l >= r) return false;
    if ((r - l + 1) % 2 != 0) return false;
    if (r - l == 1 && isGood(s[l], s[r])) return true;
    if (dp2[l][r] != -1) return dp2[l][r]; // memo

    // case1: portion between l and r are removable
    if (isGood(s[l], s[r]) && canRemove(l + 1, r - 1)) return dp2[l][r] = true;

    // case2: portion left or portion right is removable
    for (int i = l; i < r; ++i) {
      if (canRemove(l, i) && canRemove(i + 1, r)) {
        return dp2[l][r] = true;
      }
    }

    return dp2[l][r] = false;
  }

  string go(int i) {
    if (i >= s.size()) return "";
    if (dp1[i] != "Z") return dp1[i]; // memo

    string best = s[i] + go(i + 1);

    for (int r = i; r < s.size(); ++r) {
      if (canRemove(i, r)) {
        string curr = go(r + 1);

        if (curr < best) best = curr;
      }
    }

    dp1[i] = best;
    return best;
  }
};
