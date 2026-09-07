/*
 * 327. Count of Range Sum
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 2879 ms (beats 5.0%)
 * Memory: 106.6 MB (beats 87.0%)
 * Submitted: 2026-02-07 09:19:41 UTC
 * URL: https://leetcode.com/submissions/detail/1911110562/
 */

class Solution {
  public:
    int countRangeSum(vector<int> &nums, int lower, int upper) {
        int n = nums.size(), res = 0;
        long long sum = 0;
        vector<long long> prefix(n, 0);
        map<long long, int> map;
        map[0] = 1;

        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            prefix[i] = sum;

            auto it_start = map.lower_bound(prefix[i] - upper), it_end = map.upper_bound(prefix[i] - lower);
            for (auto it = it_start; it != it_end; ++it) {
                res += it->second;
            }

            map[prefix[i]] = map.count(prefix[i]) ? map[prefix[i]] + 1 : 1;
        }
        return res;
    }
};

