/*
 * 974. Subarray Sums Divisible by K
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 14 ms (beats 30.4%)
 * Memory: 37.1 MB (beats 5.7%)
 * Submitted: 2026-02-04 16:38:02 UTC
 * URL: https://leetcode.com/submissions/detail/1908168604/
 */


class Solution {
  public:
    int subarraysDivByK(vector<int> &nums, int k) {
        int n = nums.size(), res = 0;
        unordered_map<int, int> map;
        map[0] = 1;

        vector<int> prefix(n, 0);
        int sum = 0;

        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            prefix[i] = sum;

            int key = ((prefix[i] % k) + k) % k; // normalize
            if (map.count(key)) res += map[key];
            map[key]++;
        }

        return res;
    }
};

