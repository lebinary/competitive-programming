/*
 * 50. Pow(x, n)
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 8.4 MB (beats 99.8%)
 * Submitted: 2025-10-31 12:23:29 UTC
 * URL: https://leetcode.com/submissions/detail/1816819908/
 */

class Solution {
  public:
    double myPow(double x, int n) {
        if (n == 0) return 1;

        int half_n = n / 2;
        double half_x = myPow(x, half_n);

        if (n > 0) {
            if (n % 2 == 0)
                return half_x * half_x;
            else
                return x * half_x * half_x;
        } else {
            if (n % 2 == 0)
                return half_x * half_x;
            else
                return 1 / x * half_x * half_x;
        }
    }
};
