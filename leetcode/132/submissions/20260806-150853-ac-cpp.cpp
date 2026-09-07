/*
 * 132. Palindrome Partitioning II
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 35 ms (beats 86.2%)
 * Memory: 12 MB (beats 52.2%)
 * Submitted: 2026-08-06 15:08:53 UTC
 * URL: https://leetcode.com/submissions/detail/2096852065/
 */

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[n] = 0;
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        for(int i = n - 1; i >= 0; --i) {
            for(int j = i; j < n; ++j) {
                // s[i...j] is palindrome
                if(s[i] == s[j] && (j - i + 1 <= 3 || pal[i+1][j-1])) {
                    pal[i][j] = true;
                    
                    // update dp[i] = this pal + min palindromes in s[j+1 ... n] 
                    dp[i] = min(dp[i], 1 + dp[j + 1]);
                }
            }
        }

        // min cuts = min palindromes - 1
        return dp[0] - 1;
    }
};

/***
palindrom def:
"dabcbaabba"
"abba"

Approach 1: dfs(l)
r move backwards to l until its a valid pallindrome
-> 1 + dfs(r + 1) 


***/
