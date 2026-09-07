/*
 * 239. Sliding Window Maximum
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 20 ms (beats 69.7%)
 * Memory: 139 MB (beats 92.2%)
 * Submitted: 2026-02-18 03:18:49 UTC
 * URL: https://leetcode.com/submissions/detail/1922759811/
 */

class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> res;
        deque<int> dq;

        for(int i = 0; i < n; ++i) {
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);

            if(i >= k && dq.front() == i - k) dq.pop_front();

            if(i >= k - 1) res.push_back(nums[dq.front()]);
        }

        return res;
    }
};

/** monotonic queue
[1  3  -1] -3  5  3  6  7   => q = [1,3]
1  [3  -1 -3]  5  3  6  7   => q = [3]
1   3 [-1 -3  5]  3  6  7   => q = [5]
1  3  -1 [-3  5  3]  6  7   => q = [5]
1  3  -1 -3  [5  3  6]  7   => q = [5,6]
1  3  -1 -3  5  [3  6  7]   => q = [6,7]
**/
