/*
 * 239. Sliding Window Maximum
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 61 ms (beats 17.2%)
 * Memory: 153.2 MB (beats 17.5%)
 * Submitted: 2025-11-03 11:42:12 UTC
 * URL: https://leetcode.com/submissions/detail/1819493733/
 */

class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        vector<int> res;

        for(int i = 0; i < k; ++i) {
            pq.push({nums[i], i});

            if(i == k - 1) res.push_back(pq.top().first);
        }

        for(int i = k; i < n; ++i) {
            while(!pq.empty() && pq.top().second < i - k + 1) pq.pop();
            pq.push({nums[i], i});

            // store res
            res.push_back(pq.top().first);
        }

        return res;
    }
};
