/*
 * 347. Top K Frequent Elements
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 5 ms (beats 23.8%)
 * Memory: 18 MB (beats 50.2%)
 * Submitted: 2026-01-18 10:33:14 UTC
 * URL: https://leetcode.com/submissions/detail/1888779554/
 */

class Solution {
  public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            if (freq.count(num) == 0) freq[num] = 0;
            freq[num]++;
        }

        priority_queue<pair<int, int>> pq;
        for (auto [num, freq] : freq) {
            pq.push({freq, num});
        }

        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
