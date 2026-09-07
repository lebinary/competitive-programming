/*
 * 1021. Remove Outermost Parentheses
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 1 ms (beats 23.5%)
 * Memory: 9.8 MB (beats 10.6%)
 * Submitted: 2026-08-04 09:04:59 UTC
 * URL: https://leetcode.com/submissions/detail/2093738094/
 */

class Solution {
public:
    string removeOuterParentheses(string s) {
      int n = s.size();
      stack<int> st;
      vector<tuple<int, int>> primitives;

      for(int j = 0; j < n; ++j) {
        if(s[j] == '(') st.push(j);
        else {
          int i = st.top();
          st.pop();

          if(st.empty()) {
            primitives.push_back({i, j});
          }
        }
      }

      string res = "";
      for(auto [i, j] : primitives) {
        res += s.substr(i + 1, j - i - 1);
      }
      return res;       
    }
};
