/*
 * 238. Product of Array Except Self
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 3 ms (beats 37.3%)
 * Memory: 42.4 MB (beats 8.4%)
 * Submitted: 2026-01-25 09:16:21 UTC
 * URL: https://leetcode.com/submissions/detail/1896310223/
 */


class Solution {
  public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size();
        vector<int> prefix(n + 2, 1);
        vector<int> postfix(n + 2, 1);
        vector<int> res(n, 1);

        for (int i = 1; i < n + 1; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }
        for (int i = n; i > 0; i--) {
            postfix[i] = postfix[i + 1] * nums[i - 1];
        }

        for (int i = 1; i < n + 1; ++i) {
            res[i - 1] = prefix[i - 1] * postfix[i + 1];
        }

        return res;
    }
};

