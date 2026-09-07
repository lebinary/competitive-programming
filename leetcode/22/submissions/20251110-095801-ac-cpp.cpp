/*
 * 22. Generate Parentheses
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 2 ms (beats 80.0%)
 * Memory: 13.5 MB (beats 69.5%)
 * Submitted: 2025-11-10 09:58:01 UTC
 * URL: https://leetcode.com/submissions/detail/1825862107/
 */

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

