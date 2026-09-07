/*
 * 1888. Minimum Number of Flips to Make the Binary String Alternating
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 294 ms (beats 5.0%)
 * Memory: 30.5 MB (beats 5.1%)
 * Submitted: 2026-03-17 11:44:42 UTC
 * URL: https://leetcode.com/submissions/detail/1951046900/
 */

class Solution {
public:
    int minFlips(string s) {
        int n = s.size(), res = INT_MAX;
        string target1 = "", target2 = "";
        int diff1 = 0, diff2 = 0;

        // extend s to (s + s) to simulate cyclic shift
        string sDouble = s + s.substr(0, n - 1);
        
        // build target strings
        int num = 0;
        for(int i = 0; i < 2*n; ++i) {
            target1 += to_string(num);
            target2 += to_string(num^1);
            num = num^1;
        }

        // baseline
        for(int i = 0; i < n; ++i) {
            if(s[i] != target1[i]) diff1++;
            if(s[i] != target2[i]) diff2++;
        }
        res = min({res, diff1, diff2});

        // Sliding window: for every shift, check result
        for(int i = n; i < 2*n; ++i) {
            if(sDouble[i] != target1[i]) diff1++;
            if(sDouble[i] != target2[i]) diff2++;

            if(sDouble[i-n] != target1[i-n]) diff1--;
            if(sDouble[i-n] != target2[i-n]) diff2--;

            res = min({res, diff1, diff2});
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
**/
