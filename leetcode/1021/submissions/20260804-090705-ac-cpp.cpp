/*
 * 1021. Remove Outermost Parentheses
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 3 ms (beats 16.8%)
 * Memory: 9.2 MB (beats 12.4%)
 * Submitted: 2026-08-04 09:07:06 UTC
 * URL: https://leetcode.com/submissions/detail/2093740793/
 */

class Solution {
public:
    string removeOuterParentheses(string s) {
      int n = s.size();
      stack<int> st;
      string res = "";

      for(int j = 0; j < n; ++j) {
        if(s[j] == '(') st.push(j);
        else {
          int i = st.top();
          st.pop();

          if(st.empty()) {
            res += s.substr(i + 1, j - i - 1);
          }
        }
      }
      
      return res;       
    }
};
