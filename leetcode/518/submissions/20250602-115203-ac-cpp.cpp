/*
 * 518. Coin Change II
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 10 MB (beats 96.5%)
 * Submitted: 2025-06-02 11:52:03 UTC
 * URL: https://leetcode.com/submissions/detail/1651636416/
 */

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<uint> dp(amount + 1, 0);
        dp[0] = 1;

        for(int coin : coins) {
            for(int a = coin; a <= amount; ++a) {
                dp[a] += dp[a - coin];
            }
        }

        return (int)dp[amount];
    }
};
