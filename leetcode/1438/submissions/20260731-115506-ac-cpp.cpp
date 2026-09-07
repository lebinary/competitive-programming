/*
 * 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 25 ms (beats 54.4%)
 * Memory: 77.4 MB (beats 74.3%)
 * Submitted: 2026-07-31 11:55:07 UTC
 * URL: https://leetcode.com/submissions/detail/2088756977/
 */

class Solution {
  public:
    int longestSubarray(vector<int> &nums, int limit) {
        int n = nums.size(), res = 0;
        deque<int> increasing, decreasing;

        int l = 0;
        for (int r = 0; r < n; ++r) {
            while(!increasing.empty() && nums[increasing.back()] > nums[r]) {
                increasing.pop_back();
            }
            increasing.push_back(r);

            while(!decreasing.empty() && nums[decreasing.back()] < nums[r]) {
                decreasing.pop_back();
            }
            decreasing.push_back(r);

            while(l <= r && !increasing.empty() && !decreasing.empty() && abs(nums[increasing.front()] - nums[decreasing.front()]) > limit) {
                if(l == increasing.front()) increasing.pop_front();
                if(l == decreasing.front()) decreasing.pop_front();
                l++;
            }

            if(l <= r) res = max(res, r - l + 1);
        }

        return res;
    }
};

/**
Approach 1: Sliding Window + Monotonic Queue
**/
