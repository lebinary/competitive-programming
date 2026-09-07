/*
 * 1004. Max Consecutive Ones III
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 3 ms (beats 32.8%)
 * Memory: 69.6 MB (beats 70.0%)
 * Submitted: 2026-01-11 09:32:35 UTC
 * URL: https://leetcode.com/submissions/detail/1881628496/
 */

class Solution {
  public:
    int longestOnes(vector<int> &nums, int k) {
        int n = nums.size(), count = 0, best = 0;

        int l = 0;
        for (int r = 0; r < n; ++r) {
            if (nums[r] == 0) {
                while (count == k) {
                    if (nums[l] == 0) count--;
                    l++;
                }

                count++;
            }

            best = max(best, r - l + 1);
        }

        return best;
    };
};

