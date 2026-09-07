/*
 * 3133. Minimum Array End
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 1763 ms (beats 5.8%)
 * Memory: 8.7 MB (beats 85.1%)
 * Submitted: 2025-06-05 12:20:11 UTC
 * URL: https://leetcode.com/submissions/detail/1654705336/
 */

class Solution {
public:
    long long minEnd(int n, int x) {
        long long res = x;

        for(int _ = 0; _ < n - 1; ++_) {
            res += 1;
            res |= x;
        }

        return res;
    }
};
