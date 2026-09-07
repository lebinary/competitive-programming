/*
 * 162. Find Peak Element
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 12.6 MB (beats 79.3%)
 * Submitted: 2026-02-02 10:43:02 UTC
 * URL: https://leetcode.com/submissions/detail/1905334942/
 */


class Solution {
  public:
    int findPeakElement(vector<int> &nums) {
        int n = nums.size();
        return search(nums, n, 0, n);
    }

    int search(vector<int> &nums, int n, int l, int r) {
        if (l >= r) return -1;
        int m = l + (r - l) / 2;

        long long leftNei = m <= 0 ? LLONG_MIN : nums[m - 1];
        long long rightNei = m >= n - 1 ? LLONG_MIN : nums[m + 1];

        if (leftNei < nums[m] && nums[m] > rightNei) return m;

        int idx = search(nums, n, l, m);
        if (idx != -1) return idx;
        return search(nums, n, m + 1, r);
    }
};

