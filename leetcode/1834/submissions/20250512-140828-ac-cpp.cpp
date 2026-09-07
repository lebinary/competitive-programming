/*
 * 1834. Single-Threaded CPU
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 331 ms (beats 52.4%)
 * Memory: 192.2 MB (beats 84.9%)
 * Submitted: 2025-05-12 14:08:28 UTC
 * URL: https://leetcode.com/submissions/detail/1631942108/
 */

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        auto comp = [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] > b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> minHeap(comp);
        
        vector<vector<int>> queue;
        for (int i = 0; i < n; i++) {
            queue.push_back({tasks[i][0], tasks[i][1], i});
        }
        sort(queue.begin(), queue.end());
    
        vector<int> res; 
        int i = 0;
        long long t = 0;
        while(i < n || !minHeap.empty()) {
            // schedule tasks to be processed
            while(i < n && queue[i][0] <= t) {
                minHeap.push({queue[i][1], queue[i][2]});
                i++;
            }

            if (minHeap.empty()) {
                t = queue[i][0];
            } else {
                // processed only one task
                vector<int> nextTask = minHeap.top();
                minHeap.pop();

                res.push_back(nextTask[1]);
                t += nextTask[0];
            }
        }

        return res;
    }
};
