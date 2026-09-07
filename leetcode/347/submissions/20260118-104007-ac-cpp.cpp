/*
 * 347. Top K Frequent Elements
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 4 ms (beats 34.3%)
 * Memory: 18 MB (beats 74.2%)
 * Submitted: 2026-01-18 10:40:07 UTC
 * URL: https://leetcode.com/submissions/detail/1888784644/
 */

class Solution {
  public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            if (freq.count(num) == 0) freq[num] = 0;
            freq[num]++;
        }

        vector<pair<int, int>> freqVec(freq.begin(), freq.end());
        sort(freqVec.begin(), freqVec.end(), [](auto &a, auto &b) { return a.second > b.second; });

        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(freqVec[i].first);
        }

        return res;
    }
};
