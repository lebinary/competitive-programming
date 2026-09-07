/*
 * 955. Delete Columns to Make Sorted II
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 2 ms (beats 15.2%)
 * Memory: 12.9 MB (beats 58.4%)
 * Submitted: 2025-12-21 09:54:05 UTC
 * URL: https://leetcode.com/submissions/detail/1861435167/
 */

class Solution {
  public:
    int minDeletionSize(vector<string> &strs) {
        int m = strs.size(), n = strs[0].size();
        if (m == 1) return 0;

        vector<bool> sorted(m - 1, false);
        int minDel = 0;

        for (int c = 0; c < n; ++c) {
            bool del = false;
            for (int r = 0; r < m - 1; ++r) {
                if (!sorted[r] && strs[r][c] > strs[r + 1][c]) {
                    del = true;
                    break;
                }
            }

            if (del)
                minDel++;
            else {
                for (int r = 0; r < m - 1; ++r) {
                    sorted[r] = sorted[r] || strs[r][c] < strs[r + 1][c];
                }
            }
        }

        return minDel;
    }
};
