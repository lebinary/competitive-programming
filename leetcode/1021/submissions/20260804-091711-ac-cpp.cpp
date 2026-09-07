/*
 * 1021. Remove Outermost Parentheses
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 9 MB (beats 54.4%)
 * Submitted: 2026-08-04 09:17:12 UTC
 * URL: https://leetcode.com/submissions/detail/2093754079/
 */

class Solution {
public:
    string removeOuterParentheses(string s) {
      int n = s.size();
      int open = 0;
      string res = "";

      for(int i = 0; i < n; ++i) {
        if(s[i] == '(') {
          open++;
          if(open > 1) res += s[i];

        } else {
          if(open > 1) res += s[i];
          open--;
        }
      }
      
      return res;
    }
};
