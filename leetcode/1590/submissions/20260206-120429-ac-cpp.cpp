/*
 * 1590. Make Sum Divisible by P
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 96 ms (beats 11.4%)
 * Memory: 93.4 MB (beats 9.4%)
 * Submitted: 2026-02-06 12:04:30 UTC
 * URL: https://leetcode.com/submissions/detail/1910213096/
 */


class Solution {
  public:
    int minSubarray(vector<int> &nums, int p) {
        int n = nums.size();
        int best = n;
        vector<long long> prefix(n, 0);
        unordered_map<int, int> map;
        map[0] = -1;

        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            prefix[i] = sum;
        }
        if (prefix.back() % p == 0) return 0;

        for (int i = 0; i < n; ++i) {
            int q = remainder(prefix[i] - prefix[n - 1], p);
            if (map.count(q)) best = min(best, i - map[q]);

            int u = remainder(prefix[i], p);
            map[u] = map.count(u) ? max(map[u], i) : i;
        }

        return best == n ? -1 : best;
    }

    int remainder(long long nu, int de) { return ((nu % de) + de) % de; }
};

