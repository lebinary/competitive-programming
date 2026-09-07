/*
 * 3572. Maximize Y‑Sum by Picking a Triplet of Distinct X‑Values
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 116 ms (beats 31.0%)
 * Memory: 193.3 MB (beats 71.8%)
 * Submitted: 2025-06-12 10:38:15 UTC
 * URL: https://leetcode.com/submissions/detail/1661809447/
 */


class Solution {
  public:
    int maxSumDistinctTriplet(vector<int> &x, vector<int> &y) {
        // y = [6, 5, 4, 3, 2]
        // x = [3, 1, 1, 2, 2]

        int n = x.size(), res = 0;
        vector<pair<int, int>> sorted;

        for (int i = 0; i < n; ++i) {
            sorted.push_back({y[i], x[i]});
        }
        sort(sorted.rbegin(), sorted.rend());

        unordered_set<int> seen;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (count == 3) break;

            int x_i = sorted[i].second, y_i = sorted[i].first;
            if (seen.find(x_i) != seen.end()) continue;
            seen.insert(x_i);

            res += y_i;
            count++;
        }

        return count == 3 ? res : -1;
    }
};
