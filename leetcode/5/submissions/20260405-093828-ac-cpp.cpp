/*
 * 5. Longest Palindromic Substring
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 94 ms (beats 27.8%)
 * Memory: 26.1 MB (beats 25.8%)
 * Submitted: 2026-04-05 09:38:29 UTC
 * URL: https://leetcode.com/submissions/detail/1969489204/
 */

class Solution {
  public:
    string longestPalindrome(string s) {
        int n = (int)s.size();
        int resL = 0, resR = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for(int i = 0; i < n; ++i) {
            dp[i][i] = true;
            if(i + 1 < n && s[i] == s[i + 1]) {
                dp[i][i+1] = true;
                resL = i; resR = i + 1;
            }
        }

        for(int l = n - 1; l >= 0; --l) {
            for(int r = l + 1; r < n; ++r) {
                if(l + 1 >= n) continue;
                if(s[r] != s[l]) continue;

                if(l + 1 <= r - 1 && dp[l + 1][r - 1]) {
                    dp[l][r] = true;

                    if(r - l > resR - resL) {
                        resL = l;
                        resR = r;
                    }
                }
            }
        }


        return s.substr(resL, resR - resL + 1);
    };
};

