/*
 * 410. Split Array Largest Sum
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 10.4 MB (beats 73.8%)
 * Submitted: 2026-03-05 17:03:20 UTC
 * URL: https://leetcode.com/submissions/detail/1938981160/
 */

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        int l = INT_MIN, r = 0;
        for(int num : nums) {
            l = max(l, num);
            r += num;
        }

        while(l < r) {
            int m = l + (r - l) / 2;
            if(validator(nums, n, k, m)) r = m;
            else l = m + 1;
        }

        return l;
    }

    bool validator(vector<int> &nums, int n, int k, int cand) {
        int parts = 1, sum = 0;

        for(int i = 0; i < n; ++i) {
            sum += nums[i];

            if(sum > cand) {
                sum = nums[i];
                parts++;
            }

            if(parts > k) return false;
        }
        return true;
    }
};

/**
Approach: Binary search type 3
- BS on the value
- Verifier: check how many partitions can be made with the given candidate
    if #partitions > k: candidate is too small (shrink left)
    else: candidate is valid (shrink right) 
**/
