/*
 * 338. Counting Bits
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 2 ms (beats 34.8%)
 * Memory: 10.6 MB (beats 57.1%)
 * Submitted: 2025-05-15 15:09:18 UTC
 * URL: https://leetcode.com/submissions/detail/1634758018/
 */

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1, 0);
        int offset = 1;
        for (int i = 1; i < dp.size(); ++i) {
            if (offset * 2 == i) offset = i;

            dp[i] = 1 + dp[i - offset];
        }

        return dp;
    }
};
