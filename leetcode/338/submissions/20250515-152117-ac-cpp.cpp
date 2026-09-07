/*
 * 338. Counting Bits
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 10.7 MB (beats 57.1%)
 * Submitted: 2025-05-15 15:21:17 UTC
 * URL: https://leetcode.com/submissions/detail/1634767938/
 */

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1, 0);
        for (int i = 1; i < dp.size(); ++i) {
            dp[i] = dp[i >> 1] + (i & 1);
        }

        return dp;
    }
};
