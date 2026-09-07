/*
 * 209. Minimum Size Subarray Sum
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 32.1 MB (beats 100.0%)
 * Submitted: 2026-02-01 09:28:24 UTC
 * URL: https://leetcode.com/submissions/detail/1904174858/
 */


class Solution {
  public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int n = nums.size(), minLen = INT_MAX, l = 0, tot = 0;

        for (int r = 0; r < n; ++r) {
            tot += nums[r];
            while (l <= r && tot >= target) {
                minLen = min(minLen, r - l + 1);
                tot -= nums[l];
                l++;
            }
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};
