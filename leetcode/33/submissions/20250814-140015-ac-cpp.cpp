/*
 * 33. Search in Rotated Sorted Array
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 15.3 MB (beats 37.0%)
 * Submitted: 2025-08-14 14:00:15 UTC
 * URL: https://leetcode.com/submissions/detail/1734994721/
 */


class Solution {
  public:
    int search(vector<int> &nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1, m = (l + r) / 2;

        while (l <= r) {
            m = (l + r) / 2;

            // at LHS, but target is RHS
            if (nums[0] <= nums[m] && target < nums[0]) {
                l = m + 1;
            }
            // at RHS, but target is LHS
            else if (nums[m] <= nums[n - 1] && target > nums[n - 1]) {
                r = m - 1;
            }

            // else do normal binary search
            else {
                if (nums[m] == target) return m;

                // do normal binary search
                if (target > nums[m])
                    l = m + 1;
                else
                    r = m - 1;
            }
        }

        return -1;
    }
};
