/*
 * 152. Maximum Product Subarray
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 17.8 MB (beats 23.2%)
 * Submitted: 2025-12-19 12:25:32 UTC
 * URL: https://leetcode.com/submissions/detail/1859760927/
 */

class Solution {
  public:
    int maxProduct(vector<int> &nums) {
        int top = 1, bottom = 1, res = INT_MIN;

        for (int num : nums) {
            tie(top, bottom) = make_pair(max({top * num, bottom * num, num}), min({top * num, bottom * num, num}));

            res = max(res, top);
        }

        return res;
    }
};

