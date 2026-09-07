/*
 * 132. Palindrome Partitioning II
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 61 ms (beats 64.2%)
 * Memory: 12.5 MB (beats 25.0%)
 * Submitted: 2026-08-06 14:54:34 UTC
 * URL: https://leetcode.com/submissions/detail/2096833704/
 */

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, -1);
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // precompute palindrome
        for(int i = n - 1; i >= 0; --i) {
            for(int j = i; j < n; ++j) {
                if(s[i] == s[j] && (j - i + 1 <= 3 || pal[i+1][j-1])) {
                    pal[i][j] = true;
                }

            }
        }

        int palCount = dfs(s, dp, pal, 0);
        return palCount - 1;
    }

    int dfs(string& s, vector<int>& dp, vector<vector<bool>>& pal, int i) {
        if(i >= s.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int res = s.size();

        for(int j = i; j < s.size(); j++) {
            if(pal[i][j]) {
                res = min(res, 1 + dfs(s, dp, pal, j + 1)); 
            } 
        }

        return dp[i] = res;
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
