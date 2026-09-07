/*
 * 209. Minimum Size Subarray Sum
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 32 MB (beats 100.0%)
 * Submitted: 2026-03-27 19:42:16 UTC
 * URL: https://leetcode.com/submissions/detail/1961233899/
 */

// Time: 8m 16s
class Solution {
  public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int n = nums.size(), res = INT_MAX;

        int sum = 0, l = 0;
        for(int r = 0; r < n; ++r) {
            sum += nums[r];

            while(l <= r && sum - nums[l] >= target) {
                sum -= nums[l];
                l++;
            }

            if(sum >= target) res = min(res, r - l + 1);
        }

        return res == INT_MAX ? 0 : res;
    }
};

/**
# Approach 3: Binary search + Validator
- Binary seach on the length of nums
- Validator using sliding window

# Approach 2: Sliding window
- [l..r+1] ? everytime
- [l-1..r] ? when sum[l...r] - nums[l] >= target
TC: O(n)
SC: O(alpha)

# Approach 1: prefix + binary search
- Build prefix
- For each l, find the leftmost r s.t prefix[r] - prefix[l - 1] >= target
TC: O(nlogn)
SC: O(n)

**/

