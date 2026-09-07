/*
 * 826. Most Profit Assigning Work
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 596 ms (beats 13.0%)
 * Memory: 172.2 MB (beats 5.4%)
 * Submitted: 2026-02-22 06:53:41 UTC
 * URL: https://leetcode.com/submissions/detail/1927157147/
 */

class Solution {
  public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker) {
        int n = difficulty.size(), m = worker.size(), res = 0;
        vector<vector<int>> jobs(n);
        vector<int> prefixMax(n, INT_MIN);

        for (int i = 0; i < n; ++i) {
            jobs[i] = {difficulty[i], profit[i]};
        }

        sort(jobs.begin(), jobs.end(), [&](auto a, auto b) { return a[0] < b[0]; });
        sort(worker.begin(), worker.end());

        int hi = INT_MIN;
        for (int i = 0; i < n; ++i) {
            hi = max(hi, jobs[i][1]);
            prefixMax[i] = hi;
        }

        int i = n - 1;
        for (int j = m - 1; j >= 0; --j) {
            while (i >= 0 && jobs[i][0] > worker[j]) i--;
            if (i == -1) break;
            res += prefixMax[i];
        }

        return res;
    }
};
