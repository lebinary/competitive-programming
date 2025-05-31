#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string curr;
  string res;

  bool isConsec(char a, char b) { return abs(a - b) % 24 == 1; }

  string lexicographicallySmallestString(string s) {
    this->curr = "";
    this->res = s;

    dfs(0, s);
    return res;
  }

private:
  // O(2 ^ 250)
  void dfs(int i, string &s) {
    if (i >= s.size()) {
      if (curr < res)
        res = curr;
      return;
    }

    if (!curr.empty() && isConsec(s[i], curr.back())) {
      char tmp = curr.back();
      curr.pop_back();
      dfs(i + 1, s);
      curr += tmp;
    }

    curr += s[i];
    dfs(i + 1, s);
    curr.pop_back();
  }
};
