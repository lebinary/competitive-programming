/*
 * 322. Coin Change
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 31 ms (beats 59.0%)
 * Memory: 18.9 MB (beats 61.6%)
 * Submitted: 2025-06-02 01:59:37 UTC
 * URL: https://leetcode.com/submissions/detail/1651206055/
 */

class Solution {
public:
    vector<int> coins;
    vector<int> dp;

    int coinChange(vector<int>& coins, int amount) {
        this->coins = coins;
        this->dp.assign(amount + 1, -1);

        int res = dfs(amount);
        return res == INT_MAX ? -1 : res;
    }

    int dfs(int curr) {
        if(curr == 0) return 0;
        if(curr < 0) return INT_MAX;
        if(dp[curr] != -1) return dp[curr];

        int best = INT_MAX;
        for(int coin : coins) {
            best = min(best, dfs(curr - coin));
        }

        return dp[curr] = best == INT_MAX ? INT_MAX : 1 + best;
    }
};
