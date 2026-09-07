/*
 * 2466. Count Ways To Build Good Strings
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 6 ms (beats 71.2%)
 * Memory: 19.5 MB (beats 38.6%)
 * Submitted: 2025-06-18 13:46:09 UTC
 * URL: https://leetcode.com/submissions/detail/1668338045/
 */


class Solution {
    vector<int> dp;
    int mod;

  public:
    int countGoodStrings(int low, int high, int zero, int one) {
        this->dp.assign(high + 1, -1);
        this->mod = 1e9 + 7;
        return dfs(0, low, high, zero, one);
    }

    int dfs(int l, int low, int high, int zero, int one) {
        if (l > high) return 0;
        if (dp[l] != -1) return dp[l];

        int res = l >= low ? 1 : 0;

        res += dfs(l + zero, low, high, zero, one);
        res += dfs(l + one, low, high, zero, one);

        return dp[l] = (res % mod);
    }
};
