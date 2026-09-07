/*
 * 2571. Minimum Operations to Reduce an Integer to 0
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 833 ms (beats 4.6%)
 * Memory: 115.8 MB (beats 5.7%)
 * Submitted: 2025-11-27 11:10:24 UTC
 * URL: https://leetcode.com/submissions/detail/1840959763/
 */

class Solution {
  public:
    unordered_map<int, int> dp;

    int minOperations(int n) { return dfs(n); };

    int dfs(int n) {
        if (n == 0) return 0;
        if (dp.count(n)) return dp[n];

        dp[n] = INT_MAX;

        int bits = 32 - __builtin_clz(abs(n));

        int best = INT_MAX;
        for (int i = 0; i <= bits; ++i) {
            int num = 1 << i;
            int res = n > 0 ? dfs(n - num) : dfs(n + num);
            if (res != INT_MAX) best = min(best, res);
        }

        return dp[n] = best == INT_MAX ? INT_MAX : 1 + best;
    }
};
