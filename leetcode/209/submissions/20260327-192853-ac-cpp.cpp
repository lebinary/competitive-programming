/*
 * 209. Minimum Size Subarray Sum
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 11 ms (beats 4.3%)
 * Memory: 33 MB (beats 100.0%)
 * Submitted: 2026-03-27 19:28:54 UTC
 * URL: https://leetcode.com/submissions/detail/1961225880/
 */

// Time: 8m 16s
class Solution {
  public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int n = nums.size(), res = INT_MAX;
        vector<int> prefix(n, 0);

        int tot = 0;
        for(int i = 0; i < n; ++i) {
            tot += nums[i];
            prefix[i] = tot;
        }

        for(int i = 0; i < n; ++i) {
            int l = i, r = n - 1;
            while(l < r) {
                int m = l + (r - l) / 2;

                int sum = prefix[m] - (i > 0 ? prefix[i - 1] : 0);
                if(sum >= target) r = m;
                else l = m + 1;
            }

            if(prefix[l] - (i > 0 ? prefix[i - 1] : 0) >= target) {
                res = min(res, l - i + 1);
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};

/**
# Approach 1: prefix + binary search
- Build prefix
- For each l, find the leftmost r s.t prefix[r] - prefix[l - 1] >= target
**/

