/*
 * 2742. Painting the Walls
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 43 ms (beats 78.6%)
 * Memory: 120.8 MB (beats 62.4%)
 * Submitted: 2025-05-29 15:54:03 UTC
 * URL: https://leetcode.com/submissions/detail/1648103576/
 */

class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        // choose which wall to paint
        // such that sum(walls painted time) >= remaining walls
        // because remaining walls can be handled by free painters
        // => remaining walls is the "budget"
        // => "costs" is "values", "times" is "weights", "remaining time" is "budget"
        int n = cost.size();
        const int INF = 1e9;
        vector<int> dp(n + 1, INF);
        dp[0] = 0;
        
        for (int i = 0; i < n; ++i) {
            vector<int> newDP = dp;

            for(int j = 0; j <= n; ++j) {
                newDP[j] = min(newDP[j], dp[max(j - time[i] - 1, 0)] + cost[i]);
            }

            dp = newDP;
        }

        return dp[n];
    }
};
