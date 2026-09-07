/*
 * 215. Kth Largest Element in an Array
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 38 ms (beats 47.9%)
 * Memory: 61.5 MB (beats 100.0%)
 * Submitted: 2025-07-25 10:12:46 UTC
 * URL: https://leetcode.com/submissions/detail/1710831626/
 */

class Solution {
  public:
    int findKthLargest(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums) {
            minHeap.push(num);

            if (minHeap.size() > k) minHeap.pop();
        }

        return minHeap.top();
    }
};
