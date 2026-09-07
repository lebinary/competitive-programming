/*
 * 441. Arranging Coins
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 8.6 MB (beats 96.4%)
 * Submitted: 2026-02-02 11:45:09 UTC
 * URL: https://leetcode.com/submissions/detail/1905381669/
 */


class Solution {
  public:
    int arrangeCoins(int n) {
        // 1 + 2 + 3 + ... k + remainder = n
        // k(k+1)/2 <= n
        // Frame the problem as: Finding largest k s.t. k(k+1)/2 <= n

        long l = -1, r = n;
        while (l < r) {
            long k = l + (r - l + 1) / 2;
            if ((long)k * (k + 1) <= (long)2 * n) {
                l = k;
            } else {
                r = k - 1;
            }
        }

        return l;
    }
};

