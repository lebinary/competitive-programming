/*
 * 1888. Minimum Number of Flips to Make the Binary String Alternating
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 25 ms (beats 43.1%)
 * Memory: 14.3 MB (beats 90.2%)
 * Submitted: 2026-03-17 12:14:43 UTC
 * URL: https://leetcode.com/submissions/detail/1951065465/
 */

class Solution {
public:
    int minFlips(string s) {
        int n = s.size(), res = INT_MAX;
        int bit1 = 0, bit2 = 1;
        int diff1 = 0, diff2 = 0;

        // Baseline
        for(int i = 0; i < n; ++i) {
            if((s[i] - '0') != bit1) diff1++;
            if((s[i] - '0') != bit2) diff2++;

            bit1 = bit1^1;
            bit2 = bit2^1;
        }
        res = min({res, diff1, diff2});

        // Sliding window: for every shift, check result
        for(int i = n; i < 2*n; ++i) {
            int j = i % n;

            if((s[j] - '0') != bit1) diff1++;
            if((s[j] - '0') != bit2) diff2++;

            int prevBit1 = n & 1 ? bit1^1 : bit1;
            int prevBit2 = n & 1 ? bit2^1 : bit2;
            if((s[i-n] - '0') != prevBit1) diff1--;
            if((s[i-n] - '0') != prevBit2) diff2--;

            res = min({res, diff1, diff2});

            bit1 = bit1^1;
            bit2 = bit2^1;
        }

        return res;
    }
};

/**
# Ideas

111000
------
101010 diff=2
010101 diff=4

1110001
-------
1010101 diff=2
0101010 diff=5

Approach 1: bruteforce
-  Baseline
   res1 = count diff compare to first solution
   res2 = count diff compare to second solution
   res = min(res1, res2)

- while spin < n:
    spin
    res1 = count diff compare to first solution
    res2 = count diff compare to second solution
    res = min(res, res1, res2)

Approach 2: sliding window
- Idea is to eliminate repeated word, example:

    1| 110001 spin:1
    ------
    1| 010101 diff= 2 - 0 (no diff in front) + 0 (no diff added)
    0| 101011 diff= 4 - 1 (one diff in front) + 0 (no diff added)

- Baseline calulation
- while spin < n:
    if new diff as compare to res1: res1++
    if new diff as compare to res2: res2++

    if there was diff at str1[i - windowSize]: res1--
    if there was diff at str2[i - windowSize]: res2--

    res = min(res, res1, res2)

Approach 3: Sliding window optimized for O(1) Space
Similar to approach 2 but:
- instead of storing strings target1 and target2, store only current bit, bit1, bit2
- instead double the original string, use % operator on the index 
**/
