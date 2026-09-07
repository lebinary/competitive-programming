/*
 * 1004. Max Consecutive Ones III
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 4 ms (beats 21.0%)
 * Memory: 69.5 MB (beats 70.0%)
 * Submitted: 2026-02-12 09:39:13 UTC
 * URL: https://leetcode.com/submissions/detail/1916796593/
 */

class Solution {
  public:
    int longestOnes(vector<int> &nums, int k) {
        int n = nums.size(), res = 0, zeros = 0;

        int l = 0;
        for(int r = 0; r < n; ++r) {
            zeros += nums[r] == 0 ? 1 : 0;

            while(l <= r && zeros > k) {
                zeros -= nums[l] == 0 ? 1 : 0;
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    };
};
