/*
 * 1235. Maximum Profit in Job Scheduling
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 22 ms (beats 95.1%)
 * Memory: 84.2 MB (beats 76.6%)
 * Submitted: 2026-04-01 13:38:24 UTC
 * URL: https://leetcode.com/submissions/detail/1965869821/
 */

class Solution {
    int n;
    vector<int> dp;

public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        this->n = startTime.size();
        dp.assign(n, -1);
        
        vector<tuple<int, int, int>> jobs;
        for(int i = 0; i < n; ++i) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());
        
        return dfs(jobs, 0);
    }

    int dfs(vector<tuple<int, int, int>>& jobs, int i) {
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];

        auto [start, end, profit] = jobs[i];

        // pick
        int profitA = profit;
        int l = i, r = n - 1;
        while(l < r) {
            int m = l + (r - l) / 2;
            if(end <= get<0>(jobs[m])) r = m;
            else l = m + 1;
        }

        if(end <= get<0>(jobs[l])) {
            profitA += dfs(jobs, l);
        }

        // no pick
        int profitB = dfs(jobs, i + 1);

        return dp[i] = max(profitA, profitB);
    }
};
