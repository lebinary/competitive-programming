/*
 * 69. Sqrt(x)
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 8.6 MB (beats 14.2%)
 * Submitted: 2026-02-21 03:34:35 UTC
 * URL: https://leetcode.com/submissions/detail/1925893491/
 */

class Solution {
public:
    int mySqrt(int x) {
        long long l = 0, r = x;

        while(l < r) {
            long long m = l + (r - l + 1) / 2;

            if(m * m <= x) {
                l = m;
            } else {
                r = m - 1;
            }
        }

        return l;
    }
};
