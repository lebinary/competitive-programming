/*
 * 5. Longest Palindromic Substring
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 8 ms (beats 68.2%)
 * Memory: 13 MB (beats 43.9%)
 * Submitted: 2026-01-21 10:13:34 UTC
 * URL: https://leetcode.com/submissions/detail/1892012564/
 */

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
