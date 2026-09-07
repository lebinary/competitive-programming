/*
 * 560. Subarray Sum Equals K
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 41 ms (beats 62.2%)
 * Memory: 45.4 MB (beats 70.8%)
 * Submitted: 2026-01-12 11:38:15 UTC
 * URL: https://leetcode.com/submissions/detail/1882716322/
 */

class Solution {
  public:
    int subarraySum(vector<int> &nums, int k) {
        int n = nums.size(), count = 0, prefixSum = 0;
        unordered_map<int, int> sumFreq;

        for (int i = 0; i < n; ++i) {
            sumFreq[prefixSum]++;

            prefixSum += nums[i];
            if (sumFreq.count(prefixSum - k)) {
                count += sumFreq[prefixSum - k];
            }
        }

        return count;
    }
};
