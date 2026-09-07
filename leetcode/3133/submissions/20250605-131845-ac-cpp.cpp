/*
 * 3133. Minimum Array End
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 8.7 MB (beats 51.2%)
 * Submitted: 2025-06-05 13:18:46 UTC
 * URL: https://leetcode.com/submissions/detail/1654745432/
 */

class Solution {
public:
    long long minEnd(int n, int x) {
        long long res = x;
        long long i = 1, j = 1;

        while(j < n) {
            if((i & x) == 0) {
                if((j & (n - 1)) != 0) {
                    res |= i;
                }   
                
                j <<= 1;
            }

            i <<= 1;
        }

        return res;
    }
};
