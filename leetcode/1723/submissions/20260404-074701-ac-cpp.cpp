/*
 * 1723. Find Minimum Time to Finish All Jobs
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 13 ms (beats 66.0%)
 * Memory: 10.7 MB (beats 43.7%)
 * Submitted: 2026-04-04 07:47:01 UTC
 * URL: https://leetcode.com/submissions/detail/1968388833/
 */

class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();

        int time = INT_MAX;
        bool found = false;
        vector<int> workers(k, 0);
        function<void(int, int)> backtrack = [&](int i, int limit) {
            if(found) return;
            if(i >= n) {
                time = min(time, *max_element(workers.begin(), workers.end()));
                if(time <= limit) found = true;
                return;
            }

            // assign to existing workers
            int j = 0;
            while(j < k && workers[j] != 0) {
                if(workers[j] + jobs[i] <= limit) {
                    workers[j] += jobs[i];
                    backtrack(i + 1, limit);
                    workers[j] -= jobs[i];
                };

                j++;
            }

            // assign to a new worker
            if(j < k && workers[j] == 0 && workers[j] + jobs[i] <= limit) {
                workers[j] += jobs[i];
                backtrack(i + 1, limit);
                workers[j] -= jobs[i];
            }
        };

        int l = *max_element(jobs.begin(), jobs.end()), r = accumulate(jobs.begin(), jobs.end(), 0);
        while(l < r) {
            int m = l + (r - l) / 2;

            time = INT_MAX;
            found = false;
            workers.assign(k, 0);
            backtrack(0, m);

            if(time <= m) r = m;
            else l = m + 1;
        }

        return l;
    }
};
