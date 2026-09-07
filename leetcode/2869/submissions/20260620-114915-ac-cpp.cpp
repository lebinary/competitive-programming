/*
 * 2869. Minimum Operations to Collect Elements
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 23 MB (beats 25.7%)
 * Submitted: 2026-06-20 11:49:15 UTC
 * URL: https://leetcode.com/submissions/detail/2039719255/
 */

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size(), remain = k;
        vector<int> collection(k + 1, 0);

        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] <= k && collection[nums[i]] == 0) {
                collection[nums[i]] = 1;
                remain--;
            }
            if (remain == 0) {
                return n - i;
            }
        }
        return -1;
    }
};
