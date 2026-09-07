/*
 * 76. Minimum Window Substring
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 12 ms (beats 41.9%)
 * Memory: 11.8 MB (beats 16.1%)
 * Submitted: 2025-07-14 14:55:14 UTC
 * URL: https://leetcode.com/submissions/detail/1697634962/
 */


class Solution {
  public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size(), bestLen = INT_MAX;
        vector<int> best = {-1, -1};
        unordered_map<char, int> window, tCount;

        for (char c : t) {
            tCount[c] = tCount.count(c) ? tCount[c] + 1 : 0;
        }

        int l = 0, have = 0, need = tCount.size();
        for (int r = 0; r < m; ++r) {
            char rc = s[r];
            window[rc] = window.count(rc) ? window[rc] + 1 : 0;
            if (tCount.count(rc) && window[rc] == tCount[rc]) have++;

            while (have == need) {
                if (r - l + 1 < bestLen) {
                    best = {l, r};
                    bestLen = r - l + 1;
                }

                char lc = s[l];
                if (tCount.count(lc) && window[lc] == tCount[lc]) have--;
                window[lc]--;
                l++;
            }
        }

        return bestLen != INT_MAX ? s.substr(best[0], bestLen) : "";
    }
};
