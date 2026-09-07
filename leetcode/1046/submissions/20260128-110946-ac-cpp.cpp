/*
 * 1046. Last Stone Weight
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 9.8 MB (beats 98.0%)
 * Submitted: 2026-01-28 11:09:47 UTC
 * URL: https://leetcode.com/submissions/detail/1899687554/
 */

class Solution {
  public:
    int lastStoneWeight(vector<int> &stones) {
        int n = stones.size();
        if (n == 1) return stones[0];

        priority_queue<int> maxHeap;
        for (int stone : stones) {
            maxHeap.push(stone);
        }

        while (!maxHeap.empty()) {
            int first = maxHeap.top();
            maxHeap.pop();
            if (maxHeap.empty()) return first;
            int second = maxHeap.top();
            maxHeap.pop();
            if (first == second) continue;
            maxHeap.push(first - second);
        }
        return 0;
    }
};
