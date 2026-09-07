/*
 * 647. Palindromic Substrings
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 368 ms (beats 18.9%)
 * Memory: 8.6 MB (beats 59.7%)
 * Submitted: 2025-07-28 13:55:30 UTC
 * URL: https://leetcode.com/submissions/detail/1714591900/
 */

class Solution {
  public:
    int countSubstrings(string s) {
        int n = s.size(), count = 0;

        for (int i = 0; i < n; i++) {
            int l = i, r = i;
            while (l >= 0 && r < n) {
                if (!isPal(s, l, r)) break;
                count++;
                l--;
                r++;
            }

            if (i == n - 1) continue;
            l = i, r = i + 1;
            while (l >= 0 && r < n) {
                if (!isPal(s, l, r)) break;
                count++;
                l--;
                r++;
            }
        }

        return count;
    }

    bool isPal(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
