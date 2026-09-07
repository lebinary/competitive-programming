/*
 * 719. Find K-th Smallest Pair Distance
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 14.1 MB (beats 37.2%)
 * Submitted: 2026-03-05 14:18:28 UTC
 * URL: https://leetcode.com/submissions/detail/1938832547/
 */

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int l = 0, r = abs(nums.back() - nums[0]);

        while(l < r) {
            int m = l + (r - l) / 2;

            if(validator(nums, n, k, m)) r = m;
            else l = m + 1;
        }

        return l;
    }

    bool validator(vector<int> &nums, int n, int k, int cand) {
        int l = 0, count = 0;

        for(int r = 1; r < n; ++r) {
            while(l < r && abs(nums[r] - nums[l]) > cand) l++;
            count += r - l;
        }

        return count >= k;
    };
};

/**
Approach:
- BS on the value
- Validator: count how many pairs s.t. |a - b| <= cand
    => return count >= k
    
    How to validate efficiently?
    Sort first then Sliding window
    - For each r, find the first l s.t. | nums[r] - nums[l] | <= cand
      The number of pairs are going to be r - l

nums=[4, 62, 100], k = 1, cand = 96
**/
