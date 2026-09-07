/*
 * 32. Longest Valid Parentheses
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 6 ms (beats 11.2%)
 * Memory: 14.7 MB (beats 5.5%)
 * Submitted: 2026-03-14 10:19:32 UTC
 * URL: https://leetcode.com/submissions/detail/1947800816/
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), res = 0;
        vector<int> dp(n, -1);

        for(int i = 0; i < n; i++) {
            if(s[i] == ')') continue;
            res = max(res, dfs(s, dp, n, i));
        }
        return res;
    }

    int dfs(string& s, vector<int>& dp, int n, int i) {
        if(i >= n) return 0;
        if(s[i] == ')') return 0;
        if(dp[i] != -1) return dp[i];

        int res = 0;

        // case1: "()..."
        if(i + 1 < n && s[i + 1] == ')') res = max(res, 2 + dfs(s, dp, n, i + 2));
        
        // case2: "((..."
        int nextRes = dfs(s, dp, n, i + 1);
        if(i + nextRes + 1 < n && s[i + nextRes + 1] == ')') {
            int nextNextRes = dfs(s, dp, n, i + nextRes + 2);
            res = max(res, 2 + nextRes + nextNextRes );
        }
        
        return dp[i] = res;
    }
};

/**
# Approach1: DP - find longest valid substr
- ignore case start with ")"
- case1: "()..."
    res = 2 + dfs(i+2)
        - 2 is for "()"
        - dfs(i+2) is for "..."
- case2: "((...?..."
    if ? == ')':
        res = 2 + dfs(i+1) + dfs(i + dfs(i+1) + 2)
        - 2 is for the first '(' and the last ? == ')'
        - dfs(i+1) is for the inbetween "(..."
        - dfs(i + dfs(i + 1) + 2) is for the last "..."
        
**/
