/*
 * 2742. Painting the Walls
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 88 ms (beats 40.5%)
 * Memory: 122.2 MB (beats 11.7%)
 * Submitted: 2025-05-29 14:34:25 UTC
 * URL: https://leetcode.com/submissions/detail/1648041605/
 */

class Solution {
public:
    int n;
    vector<int> cost;
    vector<int> time;
    vector<vector<int>> dp;

    int paintWalls(vector<int>& cost, vector<int>& time) {
        this->cost = cost;
        this->time = time;
        this->n = cost.size();
        this->dp.assign(n, vector<int>(n + 1, -1));

        return dfs(0, n);
    }
private:
    long long encode(int i, int remain) {
        const int OFFSET = 1000;
        return static_cast<long long>(i) << 32 | static_cast<long long>(remain + OFFSET);
    }

    int dfs(int i, int remain) {
        if(remain <= 0) return 0;
        if(i >= n) return INT_MAX;
        if(dp[i][remain] != -1) return dp[i][remain];

        int best = INT_MAX;

        int paintCost = dfs(i+1, remain - 1 - time[i]);
        if(paintCost != INT_MAX) {
            best = min(best, paintCost + cost[i]);
        }

        best = min(best, dfs(i+1, remain));

        return dp[i][remain] = best;
    }  
};
