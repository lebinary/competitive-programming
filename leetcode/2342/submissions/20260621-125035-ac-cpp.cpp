/*
 * 2342. Max Sum of a Pair With Equal Sum of Digits
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 24 ms (beats 65.9%)
 * Memory: 82.6 MB (beats 25.9%)
 * Submitted: 2026-06-21 12:50:36 UTC
 * URL: https://leetcode.com/submissions/detail/2040990420/
 */

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> buckets;
        for (int num : nums) {
            int key = 0, curr = num;
            while (curr != 0) {
                key += curr % 10;
                curr /= 10;
            }
            buckets[key].push_back(num);
        }

        int res = -1;
        for (auto& [key, values] : buckets) {
            if (values.size() >= 2) {
                int first = 0, second = 0;
                for (int value : values) {
                    if (value >= first) {
                        second = first;
                        first = value;
                    } else if (value > second) {
                        second = value;
                    }
                }
                res = max(res, first + second);
            }
        }

        return res;
    }
};
