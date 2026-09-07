/*
 * 799. Champagne Tower
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 8 ms (beats 27.5%)
 * Memory: 20.4 MB (beats 35.9%)
 * Submitted: 2026-02-14 10:20:19 UTC
 * URL: https://leetcode.com/submissions/detail/1918804235/
 */

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row + 1, vector<double>(100));
        dp[0][0] = poured;
        
        for(int r = 1; r < query_row + 1; ++r) {
            for(int c = 0; c < 100; ++c) {
                if(dp[r-1][c] >= 1) dp[r][c] += (dp[r-1][c] - 1) / 2;
                if(c > 0 && dp[r-1][c-1] >= 1) dp[r][c] += (dp[r-1][c-1] - 1) / 2;
            }
        }

        return dp[query_row][query_glass] >= 1 ? 1 : dp[query_row][query_glass];
    }
};
