/*
 * 162. Find Peak Element
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 12.6 MB (beats 79.3%)
 * Submitted: 2026-02-21 09:10:43 UTC
 * URL: https://leetcode.com/submissions/detail/1926164482/
 */

class Solution {
  public:
    int findPeakElement(vector<int> &nums) {
        int n = nums.size();

        int l = 0, r = n - 1;
        while(l <= r) {
            int m = l + (r - l) / 2;

            long long leftVal = m - 1 < 0 ? LLONG_MIN : nums[m - 1];
            long long rightVal = m + 1 >= n ? LLONG_MIN : nums[m + 1];

            if(leftVal < nums[m] && nums[m] > rightVal) return m;
            else if(nums[m] <= rightVal) l = m + 1;
            else r = m - 1;
        }

        return -1;
    }
};

