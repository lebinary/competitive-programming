/*
 * 739. Daily Temperatures
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 43 ms (beats 5.1%)
 * Memory: 112 MB (beats 6.2%)
 * Submitted: 2026-01-02 08:20:49 UTC
 * URL: https://leetcode.com/submissions/detail/1871808171/
 */

class Solution {
  public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<pair<int, int>> stack;

        for (int i = 0; i < n; ++i) {
            int val = temperatures[i];
            while (!stack.empty() && stack.top().first < val) {
                auto [preVal, preIdx] = stack.top();
                stack.pop();
                res[preIdx] = i - preIdx;
            }
            stack.push({val, i});
        }

        return res;
    }
};

