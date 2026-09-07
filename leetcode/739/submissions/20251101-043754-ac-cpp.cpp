/*
 * 739. Daily Temperatures
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 143 ms (beats 5.1%)
 * Memory: 152.3 MB (beats 6.2%)
 * Submitted: 2025-11-01 04:37:54 UTC
 * URL: https://leetcode.com/submissions/detail/1817346902/
 */

class Solution {
  public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        int n = temperatures.size();
        vector<vector<int>> stack;
        vector<int> res = vector<int>(n, 0);

        for (int j = 0; j < temperatures.size(); ++j) {
            int curr = temperatures[j];

            while (stack.size() > 0 && curr > stack.back()[0]) {
                int i = stack.back()[1];
                stack.pop_back();
                res[i] = j - i;
            }

            stack.push_back({curr, j});
        }

        return res;
    }
};
