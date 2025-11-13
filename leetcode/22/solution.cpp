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
    vector<string> res;

  public:
    vector<string> generateParenthesis(int n) {
        string s = "";
        dfs(s, n, 0, 0);
        return res;
    }

    void dfs(string &s, int n, int openP, int closeP) {
        if (openP == n && closeP == n) {
            res.push_back(s);
            return;
        }

        if (openP < n) {
            s.push_back('(');
            dfs(s, n, openP + 1, closeP);
            s.pop_back();
        }

        if (closeP < openP) {
            s.push_back(')');
            dfs(s, n, openP, closeP + 1);
            s.pop_back();
        }
    }
};
