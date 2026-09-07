/*
 * 367. Valid Perfect Square
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 7.8 MB (beats 17.9%)
 * Submitted: 2026-02-21 03:43:36 UTC
 * URL: https://leetcode.com/submissions/detail/1925897873/
 */

class Solution {
public:
    bool isPerfectSquare(int num) {
        long long l = 0, r = INT_MAX;

        while(l <= r) {
            long long m = l + (r - l) / 2;
            if(m * m == num) return true;
            else if(m * m < num) l = m + 1;
            else r = m - 1;
        }

        return false;
    }
};
