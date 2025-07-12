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
    int n;
    string digits;
    vector<string> res;
    unordered_map<char, string> map;

  public:
    vector<string> letterCombinations(string digits) {
        this->digits = digits;
        this->n = digits.size();
        this->map['2'] = "abc";
        this->map['3'] = "def";
        this->map['4'] = "ghi";
        this->map['5'] = "jkl";
        this->map['6'] = "mno";
        this->map['7'] = "pqrs";
        this->map['8'] = "tuv";
        this->map['9'] = "wxyz";

        dfs("", 0);
        return res;
    };

    void dfs(string s, int i) {
        if (i >= n) {
            if (!s.empty()) res.push_back(s);
            return;
        }

        for (char c : map[digits[i]]) {
            dfs(s + c, i + 1);
        }
    }
};
