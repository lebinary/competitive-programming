/*
 * 139. Word Break
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 7 ms (beats 56.1%)
 * Memory: 13.9 MB (beats 55.5%)
 * Submitted: 2026-01-16 12:24:00 UTC
 * URL: https://leetcode.com/submissions/detail/1886778246/
 */

class Solution {
  public:
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[n] = true;

        for (int start = n - 1; start >= 0; --start) {
            for (int end = n; end > start; --end) {
                if (dp[end] && dict.count(s.substr(start, end - start))) {
                    dp[start] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};
