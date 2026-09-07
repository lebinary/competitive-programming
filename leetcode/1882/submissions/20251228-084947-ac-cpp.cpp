/*
 * 1882. Process Tasks Using Servers
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 658 ms (beats 8.8%)
 * Memory: 226.4 MB (beats 11.7%)
 * Submitted: 2025-12-28 08:49:48 UTC
 * URL: https://leetcode.com/submissions/detail/1867416387/
 */


class Solution {
  public:
    vector<int> assignTasks(vector<int> &servers, vector<int> &tasks) {
        int m = tasks.size(), n = servers.size();
        vector<int> ans(m, -1);
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> busy;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> free;
        for (int i = 0; i < n; ++i) {
            free.push({servers[i], i});
        }

        int j = 0;
        long long t = 0;
        while (j < m) {
            while (!busy.empty() && busy.top()[0] <= t) {
                int i = busy.top()[1];
                free.push({servers[i], i});
                busy.pop();
            }

            while (!free.empty() && j < m && j <= t) {
                int i = free.top()[1];
                free.pop();
                busy.push({t + tasks[j], (long long)i});
                ans[j] = i;
                j++;
            }

            t = free.empty() ? busy.top()[0] : j;
        }

        return ans;
    }
};
