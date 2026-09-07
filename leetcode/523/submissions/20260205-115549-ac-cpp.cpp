/*
 * 523. Continuous Subarray Sum
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 92 ms (beats 11.3%)
 * Memory: 156.8 MB (beats 5.2%)
 * Submitted: 2026-02-05 11:55:49 UTC
 * URL: https://leetcode.com/submissions/detail/1909058835/
 */


class Solution {
  public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        int n = nums.size(), sum = 0;
        vector<long> prefix(n, 0);
        unordered_map<int, int> map;
        map[0] = -1;

        for (int j = 0; j < n; ++j) {
            sum += nums[j];
            prefix[j] = sum;
            int key = (prefix[j] % k + k) % k;

            if (map.count(key) && j - map[key] >= 2) return true;

            if (!map.count(key)) map[key] = j;
        }

        return false;
    }
};

