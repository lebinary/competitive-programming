/*
 * 2444. Count Subarrays With Fixed Bounds
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 7 ms (beats 21.0%)
 * Memory: 94 MB (beats 36.8%)
 * Submitted: 2026-02-17 03:11:41 UTC
 * URL: https://leetcode.com/submissions/detail/1921658321/
 */


// Time taken: 1 hr 47 m 58 s. Hints used: 3
class Solution {
  public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK) {
        int n = nums.size();
        long long res = 0;

        int lastMinK = -1, lastMaxK = -1;
        int lmin = 0, lmax = 0;

        for(int r = 0; r < n; ++r) {
            if(nums[r] < minK || nums[r] > maxK) {
                lastMinK = lastMaxK = -1;
                lmin = lmax = r + 1;
                continue;
            }

            if(nums[r] == minK) lastMinK = r;
            if(nums[r] == maxK) lastMaxK = r;

            if(lastMinK != -1 && lastMaxK != -1) {
                lmax = min(lastMinK, lastMaxK) + 1;
                res += lmax - lmin;
            }
        }

        return res;
    }
};
