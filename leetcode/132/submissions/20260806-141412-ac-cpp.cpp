/*
 * 132. Palindrome Partitioning II
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 1629 ms (beats 24.1%)
 * Memory: 9.4 MB (beats 77.1%)
 * Submitted: 2026-08-06 14:14:13 UTC
 * URL: https://leetcode.com/submissions/detail/2096780827/
 */

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, -1);
        int palCount = dfs(s, dp, 0);
        return palCount - 1;
    }

    int dfs(string& s, vector<int>& dp, int startIdx) {
        if(startIdx >= s.size()) return 0;
        if(dp[startIdx] != -1) return dp[startIdx];

        int res = s.size();

        for(int endIdx = s.size() - 1; endIdx >= startIdx; endIdx--) {
            int l = startIdx, r = endIdx;
            while(l <= r && s[l] == s[r]) {
                l++;
                r--;
            }

            if(l > r) res = min(res, 1 + dfs(s, dp, endIdx + 1)); 
        }

        return dp[startIdx] = res;
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
