/*
 * 1834. Single-Threaded CPU
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 345 ms (beats 43.7%)
 * Memory: 192.3 MB (beats 84.7%)
 * Submitted: 2025-05-11 13:07:49 UTC
 * URL: https://leetcode.com/submissions/detail/1631050960/
 */

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        auto comp = [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] > b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> available(comp);
        
        vector<vector<int>> queue;
        for (int i = 0; i < n; i++) {
            queue.push_back({tasks[i][0], tasks[i][1], i});
        }
        sort(queue.begin(), queue.end());
    
        vector<int> res; 
        int i = 0;
        long long t = 0;
        while(i < n || !available.empty()) {
            // if no availble tasks, jump to the next index, make sure time is not behind
            if (available.empty() && i < n) {
                t = max(t, (long long)queue[i][0]);
            }

            // schedule tasks to be processed
            while(i < n && queue[i][0] <= t) {
                available.push({queue[i][1], queue[i][2]});
                i++;
            }

            // processed only one task
            vector<int> nextTask = available.top();
            available.pop();

            res.push_back(nextTask[1]);
            t += nextTask[0];
        }

        return res;
    }
};
