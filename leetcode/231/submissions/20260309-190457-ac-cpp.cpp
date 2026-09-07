/*
 * 231. Power of Two
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 7.7 MB (beats 81.8%)
 * Submitted: 2026-03-09 19:04:57 UTC
 * URL: https://leetcode.com/submissions/detail/1943240079/
 */

class Solution {
public:
    bool isPowerOfTwo(int n) {
        int ones = 0;
        while(n > 0) {
            if(n & 1) ones++;
            if(ones > 1) return false;
            n >>= 1; 
        }
        return ones == 1;
    }
};

/**
Approach 1: keep time 2 until exact equal n, if exceed return false
Approach 2: binary form has exactly 1 one, and the rest are zeroes
    - i.e: 
        1: 1
        2: 10
        4: 100
        8: 1000
        ...
**/
