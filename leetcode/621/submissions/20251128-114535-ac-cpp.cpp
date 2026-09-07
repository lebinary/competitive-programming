/*
 * 621. Task Scheduler
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 14 ms (beats 56.6%)
 * Memory: 63.4 MB (beats 5.0%)
 * Submitted: 2025-11-28 11:45:35 UTC
 * URL: https://leetcode.com/submissions/detail/1841722728/
 */

class Solution {
  public:
    int leastInterval(vector<char> &tasks, int n) {
        priority_queue<int> maxHeap;
        queue<vector<int>> q;

        vector<int> tmp = vector<int>(26, 0);
        for (char task : tasks) {
            tmp[task - 'A'] += 1;
        }
        for (int i = 0; i < 26; ++i) {
            if (tmp[i] > 0) maxHeap.push(tmp[i]);
        }

        int t = 0;
        while (!maxHeap.empty() || !q.empty()) {
            t++;

            if (!maxHeap.empty()) {
                int freq = maxHeap.top();
                maxHeap.pop();
                if (freq > 1) q.push({freq - 1, t + n});
            }

            if (!q.empty() && q.front()[1] == t) {
                int freq = q.front()[0];
                q.pop();
                maxHeap.push(freq);
            }
        }

        return t;
    }
};
