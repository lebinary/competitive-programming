/*
 * 134. Gas Station
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 112.5 MB (beats 25.8%)
 * Submitted: 2025-07-15 14:21:08 UTC
 * URL: https://leetcode.com/submissions/detail/1698891829/
 */


class Solution {
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        int start = 0, curr = 0, total = 0;

        for (int i = 0; i < n; ++i) {
            int net = gas[i] - cost[i];
            curr += net;
            total += net;

            if (curr < 0) {
                start = i + 1;
                curr = 0;
            }
        }

        return total >= 0 ? start : -1;
    }
};
