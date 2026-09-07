/*
 * 1371. Find the Longest Substring Containing Vowels in Even Counts
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 405 ms (beats 12.8%)
 * Memory: 127.9 MB (beats 5.5%)
 * Submitted: 2026-02-05 14:14:40 UTC
 * URL: https://leetcode.com/submissions/detail/1909183735/
 */

class Solution {
  public:
    int findTheLongestSubstring(string s) {
        int n = s.size(), best = 0;
        vector<int> parity(5, 0);
        unordered_map<int, int> map;
        map[0] = -1;

        for (int j = 0; j < n; ++j) {
            int v = getVowelIdx(s[j]);
            if (v != -1) parity[v] ^= 1;

            int key = hash(parity);
            if (map.count(key))
                best = max(best, j - map[key]);
            else
                map[key] = j;
        }

        return best;
    }

    int hash(vector<int> binVec) {
        int mask = 0;
        for (int d = 0; d < binVec.size(); ++d) {
            mask |= (binVec[d] << d);
        }
        return mask;
    }

    int getVowelIdx(char c) {
        if (c == 'a') return 0;
        if (c == 'e') return 1;
        if (c == 'i') return 2;
        if (c == 'o') return 3;
        if (c == 'u') return 4;
        return -1;
    }
};

