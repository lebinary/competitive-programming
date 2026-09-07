/*
 * 3701. Compute Alternating Sum
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 32.5 MB (beats 79.4%)
 * Submitted: 2026-06-20 11:21:15 UTC
 * URL: https://leetcode.com/submissions/detail/2039696578/
 */

class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i & 1) {
                res += (nums[i] * -1);
            } else {
                res += nums[i];
            }
        }
        return res;
    }
};
