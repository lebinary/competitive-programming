/*
 * 239. Sliding Window Maximum
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 30 ms (beats 33.3%)
 * Memory: 139.1 MB (beats 74.2%)
 * Submitted: 2025-11-03 12:10:26 UTC
 * URL: https://leetcode.com/submissions/detail/1819512810/
 */

class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> res;
        deque<int> dq; // dq will have 2 propeties: (i1 < i2 < i3 < ...) && (nums[i1] > nums[i2] > nums[i3] > ...)

        for (int i = 0; i < n; ++i) {
            if (!dq.empty() && dq.front() < i - k + 1) dq.pop_front();

            while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();

            dq.push_back(i);
            if (i >= k - 1) res.push_back(nums[dq.front()]);
        }

        return res;
    }
};
