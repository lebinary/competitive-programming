/*
 * 621. Task Scheduler
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 13 ms (beats 57.4%)
 * Memory: 38.1 MB (beats 99.8%)
 * Submitted: 2025-11-28 12:08:02 UTC
 * URL: https://leetcode.com/submissions/detail/1841733171/
 */

class Solution {
  public:
    int leastInterval(vector<char> &tasks, int n) {
        priority_queue<int> maxHeap;

        vector<int> tmp = vector<int>(26, 0);
        for (char task : tasks) {
            tmp[task - 'A'] += 1;
        }
        for (int i = 0; i < 26; ++i) {
            if (tmp[i] > 0) maxHeap.push(tmp[i]);
        }

        int t = 0;
        while (!maxHeap.empty()) {
            int taskCount = 0, cycle = n + 1;
            tmp = {};

            for (int i = 0; i < cycle; ++i) {
                if (maxHeap.empty()) break;
                int freq = maxHeap.top();
                maxHeap.pop();
                if (freq > 1) tmp.push_back(freq - 1);
                taskCount++;
            }

            for (int freq : tmp) maxHeap.push(freq);
            t += maxHeap.empty() ? taskCount : cycle;
        }

        return t;
    }
};
