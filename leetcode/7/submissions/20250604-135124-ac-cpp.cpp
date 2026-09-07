/*
 * 7. Reverse Integer
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 8.6 MB (beats 54.2%)
 * Submitted: 2025-06-04 13:51:24 UTC
 * URL: https://leetcode.com/submissions/detail/1653763595/
 */

class Solution {
public:
    int reverse(int x) {
        long res = go(x, 0);
        if(res < INT_MIN || res > INT_MAX) return 0;

        return (int)res;
    }

    long go(int num, long acc) {
        if(num == 0) return acc;

        int d = num % 10;
        int withoutD = num / 10;

        return go(withoutD, acc * 10 + d);
    }
};
