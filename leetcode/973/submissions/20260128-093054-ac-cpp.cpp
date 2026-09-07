/*
 * 973. K Closest Points to Origin
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 26 ms (beats 87.6%)
 * Memory: 68.4 MB (beats 68.5%)
 * Submitted: 2026-01-28 09:30:55 UTC
 * URL: https://leetcode.com/submissions/detail/1899605001/
 */

class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        int n = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (int i = 0; i < n; ++i) {
            int dist = pow(points[i][0], 2) + pow(points[i][1], 2);
            minHeap.push({dist, i});
        }

        vector<vector<int>> res;
        for (int _ = 0; _ < k; ++_) {
            auto [dist, i] = minHeap.top();
            minHeap.pop();

            res.push_back(points[i]);
        }

        return res;
    }
};
