/*
 * 1004. Max Consecutive Ones III
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 4 ms (beats 21.0%)
 * Memory: 70.3 MB (beats 38.4%)
 * Submitted: 2026-01-11 09:20:59 UTC
 * URL: https://leetcode.com/submissions/detail/1881619929/
 */

class Solution {
  public:
    int longestOnes(vector<int> &nums, int k) {
        int n = nums.size(), flipCount = 0, best = 0;
        vector<bool> flipped(n, false);

        int l = 0;
        for (int r = 0; r < n; ++r) {
            if (nums[r] == 0) {
                if (flipCount == k) {
                    while (l < r && !flipped[l]) l++;
                    flipped[l++] = false;
                    flipCount--;
                }

                flipped[r] = true;
                flipCount++;
            }

            best = max(best, r - l + 1);
        }

        return best;
    };
};
