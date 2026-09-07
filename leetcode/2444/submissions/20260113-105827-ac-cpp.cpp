/*
 * 2444. Count Subarrays With Fixed Bounds
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 93.9 MB (beats 36.8%)
 * Submitted: 2026-01-13 10:58:27 UTC
 * URL: https://leetcode.com/submissions/detail/1883721998/
 */

class Solution {
  public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK) {
        int n = nums.size();
        long long count = 0;
        int leftBound = -1, lastMin = -1, lastMax = -1;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == minK) lastMin = i;
            if (nums[i] == maxK) lastMax = i;
            if (nums[i] < minK || nums[i] > maxK) leftBound = i;

            count += max(0, min(lastMin, lastMax) - leftBound);
        }

        return count;
    }
};
