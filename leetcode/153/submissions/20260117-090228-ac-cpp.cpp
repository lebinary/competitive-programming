/*
 * 153. Find Minimum in Rotated Sorted Array
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 14.1 MB (beats 79.8%)
 * Submitted: 2026-01-17 09:02:28 UTC
 * URL: https://leetcode.com/submissions/detail/1887567866/
 */

class Solution {
  public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l = 0, r = n - 1;

        while (l < r) {
            int m = l + (r - l) / 2;

            if (nums[m] > nums[r]) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        return nums[l];
    }
};
