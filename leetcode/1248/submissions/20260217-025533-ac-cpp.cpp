/*
 * 1248. Count Number of Nice Subarrays
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 12 ms (beats 39.4%)
 * Memory: 71.4 MB (beats 70.0%)
 * Submitted: 2026-02-17 02:55:33 UTC
 * URL: https://leetcode.com/submissions/detail/1921650287/
 */


// Time taken: 
// 
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        int oddsMin = 0, oddsMax = 0;
        int lmin = 0, lmax = 0;

        for(int r = 0; r < n; ++r) {
            if(nums[r] % 2 != 0) {
                oddsMax++;
                oddsMin++;
            }

            while(lmax <= r && oddsMax >= k) {
                if(nums[lmax] % 2 != 0) oddsMax--;
                lmax++;
            }

            while(lmin <= r && oddsMin > k) {
                if(nums[lmin] % 2 != 0) oddsMin--;
                lmin++;
            }

            if(oddsMin == k) res += lmax - lmin;
        }

        
        return res;
    }
};
