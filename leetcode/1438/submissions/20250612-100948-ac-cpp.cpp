/*
 * 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 546 ms (beats 5.1%)
 * Memory: 173.1 MB (beats 7.2%)
 * Submitted: 2025-06-12 10:09:49 UTC
 * URL: https://leetcode.com/submissions/detail/1661785257/
 */


class Solution {
  public:
    int longestSubarray(vector<int> &nums, int limit) {
        if (nums.size() == 1) return 1;

        int n = nums.size(), res = 0;
        priority_queue<vector<int>> maxHeap;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        for (int l = 0, r = 0; r < n; ++r) {
            maxHeap.push({nums[r], r});
            minHeap.push({nums[r], r});

            while (l <= r) {
                while (!maxHeap.empty() && maxHeap.top()[1] < l) maxHeap.pop();
                while (!minHeap.empty() && minHeap.top()[1] < l) minHeap.pop();

                if (maxHeap.empty() || minHeap.empty()) break;
                if (maxHeap.top()[0] - minHeap.top()[0] <= limit) break;

                l++;
            }
            res = max(res, r - l + 1);
        }

        return res;
    }
};
