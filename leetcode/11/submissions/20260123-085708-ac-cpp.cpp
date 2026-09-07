/*
 * 11. Container With Most Water
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 3 ms (beats 34.2%)
 * Memory: 63 MB (beats 49.0%)
 * Submitted: 2026-01-23 08:57:09 UTC
 * URL: https://leetcode.com/submissions/detail/1894147677/
 */


class Solution {
  public:
    int maxArea(vector<int> &height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int best = 0;

        while (l < r) {
            best = max(best, min(height[l], height[r]) * (r - l));

            if (height[l] <= height[r])
                l++;
            else
                r--;
        }

        return best;
    }
};
