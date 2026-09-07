/*
 * 1899. Merge Triplets to Form Target Triplet
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 3 ms (beats 61.0%)
 * Memory: 150.7 MB (beats 33.5%)
 * Submitted: 2026-01-16 05:33:33 UTC
 * URL: https://leetcode.com/submissions/detail/1886478344/
 */

class Solution {
  public:
    bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target) {
        unordered_set<int> good;

        for (vector<int> &t : triplets) {
            if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2]) continue;

            for (int i = 0; i < 3; i++) {
                if (t[i] == target[i]) good.insert(i);
            }
        }

        return good.size() == 3;
    }
};
