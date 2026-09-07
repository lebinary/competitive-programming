/*
 * 930. Binary Subarrays With Sum
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 4 ms (beats 45.2%)
 * Memory: 32.6 MB (beats 62.4%)
 * Submitted: 2026-02-17 02:46:10 UTC
 * URL: https://leetcode.com/submissions/detail/1921645666/
 */

// Time taken: 7 m 38 s
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(), res = 0;
        int sumMin = 0, sumMax = 0;
        int lmin = 0, lmax = 0;

        for(int r = 0; r < n; ++r) {
            sumMax += nums[r];
            sumMin += nums[r];

            while(lmax <= r && sumMax >= goal) {
                sumMax -= nums[lmax++];
            }

            while(lmin <= r && sumMin > goal) {
                sumMin -= nums[lmin++];
            }

            if(sumMin == goal) res += lmax - lmin;
        }

        return res;
    }
};
