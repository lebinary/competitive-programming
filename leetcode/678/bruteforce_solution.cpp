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
    vector<char> par;
    string s;

  public:
    bool checkValidString(string s) {
        this->s = s;
        return dfs(0);
    }

    bool dfs(int i) {
        if (i >= s.size()) return par.empty();

        bool res = false;

        char c = s[i];
        if (c == '(') {
            par.push_back('(');
            res = dfs(i + 1);
            par.pop_back();
            return res;
        } else if (c == ')') {
            if (!par.empty() && par.back() == '(') {
                par.pop_back();
                res = dfs(i + 1);
                par.push_back('(');
                return res;
            }
            return false;
        }

        // '*' as empty
        if (dfs(i + 1)) return true;

        // '*' as '('
        par.push_back('(');
        res = dfs(i + 1);
        par.pop_back();
        if (res) return true;

        // '*' aas ')'
        if (!par.empty() && par.back() == '(') {
            par.pop_back();
            res = dfs(i + 1);
            par.push_back('(');
            if (res) return res;
        }

        return false;
    }
};
