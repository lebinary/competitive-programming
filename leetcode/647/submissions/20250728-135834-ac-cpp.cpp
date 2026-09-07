/*
 * 647. Palindromic Substrings
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 1 ms (beats 92.0%)
 * Memory: 8.6 MB (beats 59.7%)
 * Submitted: 2025-07-28 13:58:35 UTC
 * URL: https://leetcode.com/submissions/detail/1714595755/
 */

class Solution {
  public:
    int countSubstrings(string s) {
        int n = s.size(), count = 0;

        for (int i = 0; i < n; i++) {
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                count++;
                l--;
                r++;
            }

            l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                count++;
                l--;
                r++;
            }
        }

        return count;
    }
};
