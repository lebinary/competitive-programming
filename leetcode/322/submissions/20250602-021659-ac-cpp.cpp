/*
 * 322. Coin Change
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 19 ms (beats 80.8%)
 * Memory: 18 MB (beats 62.8%)
 * Submitted: 2025-06-02 02:16:59 UTC
 * URL: https://leetcode.com/submissions/detail/1651213626/
 */

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for(int i = 0; i < dp.size(); i++) {
            for(int c : coins) {
                if(i >= c && dp[i - c] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - c] + 1);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
