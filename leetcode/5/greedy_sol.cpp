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
    string longestPalindrome(string s) {
        int n = s.size();
        string res{s[0]};

        for (int i = 0; i < n; ++i) {
            if (i < n - 1 && s[i] == s[i + 1]) {
                expand(s, res, n, i, i + 1);
            }
            expand(s, res, n, i, i);
        }

        return res;
    };

    void expand(string &s, string &res, int n, int l, int r) {
        while (l >= 0 && r < n && s[l] == s[r]) {
            l--;
            r++;
        };
        if (r - l - 1 > res.size()) {
            res = s.substr(l + 1, r - l - 1);
        }
    };
};
