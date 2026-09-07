/*
 * 1915. Number of Wonderful Substrings
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 262 ms (beats 23.2%)
 * Memory: 19.6 MB (beats 58.8%)
 * Submitted: 2026-02-06 10:44:07 UTC
 * URL: https://leetcode.com/submissions/detail/1910153997/
 */


class Solution {
  public:
    long long wonderfulSubstrings(string word) {
        int n = word.size(), m = 'j' - 'a' + 1;
        long long res = 0;
        int bmParity = 0;
        unordered_map<int, long long> map;
        map[0] = 1;

        for (int i = 0; i < n; ++i) {
            bmParity ^= (1 << (word[i] - 'a'));

            if (map.count(bmParity)) res += map[bmParity];

            for (int j = 0; j < m; ++j) {
                bmParity ^= (1 << j);
                if (map.count(bmParity)) res += map[bmParity];
                bmParity ^= (1 << j);
            }

            map[bmParity]++;
        }

        return res;
    }
};

