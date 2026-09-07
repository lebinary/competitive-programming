/*
 * 1249. Minimum Remove to Make Valid Parentheses
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 15 ms (beats 17.5%)
 * Memory: 13.9 MB (beats 79.8%)
 * Submitted: 2026-01-01 14:19:42 UTC
 * URL: https://leetcode.com/submissions/detail/1871072719/
 */

class Solution {
  public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        vector<pair<char, int>> stack;
        unordered_set<int> invalid;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '(')
                stack.push_back({s[i], i});
            else if (s[i] == ')') {
                if (stack.empty())
                    invalid.insert(i);
                else
                    stack.pop_back();
            }
        }

        for (auto [val, idx] : stack) {
            invalid.insert(idx);
        }

        string res = "";
        for (int i = 0; i < s.size(); ++i) {
            if (invalid.count(i)) continue;
            res += s[i];
        }

        return res;
    }
};
