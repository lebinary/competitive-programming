/*
 * 1899. Merge Triplets to Form Target Triplet
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 82 ms (beats 6.2%)
 * Memory: 170.9 MB (beats 6.9%)
 * Submitted: 2026-01-16 05:22:43 UTC
 * URL: https://leetcode.com/submissions/detail/1886469697/
 */

class Solution {
  public:
    bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target) {
        int R = triplets.size(), C = triplets[0].size();
        unordered_set<int> ignoreRows;

        for (int c = 0; c < C; ++c) {
            for (int r = 0; r < R; ++r) {
                if (triplets[r][c] > target[c]) ignoreRows.insert(r);
            }
        }

        for (int c = 0; c < C; ++c) {
            int largest = INT_MIN;
            for (int r = 0; r < R; ++r) {
                if (ignoreRows.count(r)) continue;
                largest = max(largest, triplets[r][c]);
            }
            if (largest != target[c]) return false;
        }

        return true;
    }
};
