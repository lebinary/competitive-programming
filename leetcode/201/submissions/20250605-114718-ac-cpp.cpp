/*
 * 201. Bitwise AND of Numbers Range
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 3 ms (beats 30.1%)
 * Memory: 11.3 MB (beats 47.0%)
 * Submitted: 2025-06-05 11:47:19 UTC
 * URL: https://leetcode.com/submissions/detail/1654683489/
 */

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int i = 0;
        while(left >> i != right >> i && i < 32) {
            i++;
        }

        return (left >> i & right >> i) << i;
    }
};
