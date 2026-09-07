/*
 * 42. Trapping Rain Water
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 25.8 MB (beats 93.6%)
 * Submitted: 2025-07-15 11:40:34 UTC
 * URL: https://leetcode.com/submissions/detail/1698730099/
 */


class Solution {
  public:
    int trap(vector<int> &height) {
        int n = height.size(), res = 0;
        int l = 0, r = n - 1;
        int maxL = height[l], maxR = height[r];

        while (l < r) {
            if (maxL < maxR) {
                res += max(0, maxL - height[l++]);
                maxL = max(maxL, height[l]);
            } else {
                res += max(0, maxR - height[r--]);
                maxR = max(maxR, height[r]);
            }
        }

        return res;
    }
};
