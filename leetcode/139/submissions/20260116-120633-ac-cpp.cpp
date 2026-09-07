/*
 * 139. Word Break
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 15 ms (beats 28.2%)
 * Memory: 16.8 MB (beats 30.2%)
 * Submitted: 2026-01-16 12:06:33 UTC
 * URL: https://leetcode.com/submissions/detail/1886766485/
 */

class Solution {
  public:
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        vector<int> dp(s.size() + 1, -1);
        return dfs(s, dp, dict, 0);
    }

    bool dfs(string &s, vector<int> &dp, unordered_set<string> &dict, int start) {
        if (start >= s.size()) return true;
        if(dp[start] != -1) return dp[start];

        for (int end = start + 1; end <= s.size(); end++) {
            if (dict.count(s.substr(start, end - start)) == 0) continue;

            if (dfs(s, dp, dict, end)) return dp[start] = true;
        }

        return dp[start] = false;
    }
};
