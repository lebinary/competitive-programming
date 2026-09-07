/*
 * 239. Sliding Window Maximum
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 359 ms (beats 6.6%)
 * Memory: 229.2 MB (beats 5.0%)
 * Submitted: 2025-06-12 01:30:07 UTC
 * URL: https://leetcode.com/submissions/detail/1661360640/
 */


class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        int n = nums.size();
        priority_queue<vector<int>> maxHeap;
        vector<int> res;

        for (int i = 0; i < nums.size(); ++i) {
            maxHeap.push({nums[i], i});

            // initial window, skip
            if (i < k - 1) continue;

            // clean up phase
            while (!maxHeap.empty() && maxHeap.top()[1] < i - k + 1) maxHeap.pop();
            if (maxHeap.empty()) continue; // just formality, its not going to be empty since nums[i] will always be here

            res.push_back(maxHeap.top()[0]);
        }

        return res;
    }
};
