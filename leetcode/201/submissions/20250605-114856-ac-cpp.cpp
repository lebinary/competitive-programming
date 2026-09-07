/*
 * 201. Bitwise AND of Numbers Range
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 11.3 MB (beats 9.8%)
 * Submitted: 2025-06-05 11:48:56 UTC
 * URL: https://leetcode.com/submissions/detail/1654684547/
 */

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int i = 0;
        while(left != right && i < 32) {
            left >>= 1;
            right >>= 1;
            i++;
        }

        return left << i;
    }
};
