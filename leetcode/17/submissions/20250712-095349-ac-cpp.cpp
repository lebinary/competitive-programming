/*
 * 17. Letter Combinations of a Phone Number
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 9.4 MB (beats 43.1%)
 * Submitted: 2025-07-12 09:53:50 UTC
 * URL: https://leetcode.com/submissions/detail/1695102572/
 */


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
