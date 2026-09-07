/*
 * 2444. Count Subarrays With Fixed Bounds
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 210 ms (beats 5.3%)
 * Memory: 137.9 MB (beats 5.1%)
 * Submitted: 2026-02-16 05:17:37 UTC
 * URL: https://leetcode.com/submissions/detail/1920664890/
 */

class Solution {
  public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK) {
        int n = nums.size();
        long long res = 0;

        unordered_map<int, int> mapMin, mapMax;
        int lmin = 0, lmax = 0;

        for(int r = 0; r < n; ++r) {
            if(nums[r] < minK || nums[r] > maxK) {
                mapMin.clear(); mapMax.clear();
                lmin = r + 1; lmax = r + 1;
                continue;
            }

            mapMax[nums[r]]++;
            mapMin[nums[r]]++;

            while(lmax <= r && mapMax.count(minK) && mapMax.count(maxK)) {
                mapMax[nums[lmax]]--;
                if(mapMax[nums[lmax]] == 0) mapMax.erase(nums[lmax]);
                lmax++;
            }

            if(mapMin.count(minK) && mapMin.count(maxK)) {
                res += lmax - lmin;
            }
        }

        return res;
    }
};

/**

nums = [1,3,5,7,2,1,5]


[2,1,5]


[135]
[1352]
[13521] [3521] [521]


nums = [1,1,1]
res = 6

[2,1,5,3,1,5]

[215] [15]
[2153] [153]
[21531] [1531] [531]

r = 2: [2,1,5] 


[1,3,5,2,7,1,5]


**/
