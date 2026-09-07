/*
 * 45. Jump Game II
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 20.4 MB (beats 96.3%)
 * Submitted: 2025-10-31 11:33:28 UTC
 * URL: https://leetcode.com/submissions/detail/1816791226/
 */

class Solution {
  public:
    int jump(vector<int> &nums) {
        int n = nums.size(), l = 0, r = 0, count = 0;

        while (true) {
            if (r >= n - 1) break;

            int furthest = r;
            for (int i = l; i <= r; ++i) {
                furthest = max(furthest, i + nums[i]);
            }

            l = r + 1;
            r = furthest;
            count++;
        }

        return count;
    }
};
