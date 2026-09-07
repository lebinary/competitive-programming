/*
 * 209. Minimum Size Subarray Sum
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 32.2 MB (beats 100.0%)
 * Submitted: 2026-02-12 09:07:49 UTC
 * URL: https://leetcode.com/submissions/detail/1916765511/
 */

class Solution {
  public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int n = nums.size(), sum = 0, res = INT_MAX;
        
        int l = 0;
        for(int r = 0; r < n; ++r) {
            sum += nums[r];

            while(l <= r && sum - nums[l] >= target) {
                sum -= nums[l++];
            }

            if(sum >= target) {
                res = min(res, r - l + 1);
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};

