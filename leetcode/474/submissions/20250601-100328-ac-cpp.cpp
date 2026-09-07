/*
 * 474. Ones and Zeroes
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 186 ms (beats 27.6%)
 * Memory: 105.7 MB (beats 44.7%)
 * Submitted: 2025-06-01 10:03:28 UTC
 * URL: https://leetcode.com/submissions/detail/1650591297/
 */

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for(string str : strs) {
            int zeroes = 0, ones = 0;
            for(char c : str) {
                if(c == '0') zeroes++;
                else ones++;
            }

            vector<vector<int>> newdp = dp;
            for(int i = 0; i <= m; ++i) {
                for(int j = 0; j <= n; ++j) {
                    if(i >= zeroes && j >= ones) {              
                        newdp[i][j] = max(dp[i][j], 1 + dp[i - zeroes][j - ones]);
                    }
                }
            }

            dp = newdp;
        }

        return dp[m][n];
    }
};
