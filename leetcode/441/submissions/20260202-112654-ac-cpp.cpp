/*
 * 441. Arranging Coins
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 8.9 MB (beats 36.9%)
 * Submitted: 2026-02-02 11:26:55 UTC
 * URL: https://leetcode.com/submissions/detail/1905368592/
 */

class Solution {
  public:
    int arrangeCoins(int n) {
        // 1 + 2 + 3 + ... + k + remainder = n
        // 1 + 2 + 3 + ... + k <= n
        // k(k+1) <= 2n
        // k^2 + k <= 2n
        // k^2 + k + 1/4 <= 2n + 1/4
        // (k + 1/2)^2 <= 2n + 1/4
        // k + 1/2 <= sqrt(2n + 1/4)

        return sqrt((double)2 * n + 0.25) - 0.5;
    }
};
