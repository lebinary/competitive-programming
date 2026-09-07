/*
 * 424. Longest Repeating Character Replacement
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 2 ms (beats 71.4%)
 * Memory: 10.8 MB (beats 93.4%)
 * Submitted: 2026-01-28 13:44:38 UTC
 * URL: https://leetcode.com/submissions/detail/1899814008/
 */


class Solution {
  public:
    int characterReplacement(string s, int k) {
        int n = s.size(), l = 0, maxFreq = 0;
        vector<int> freq(26, 0);

        for (int r = 0; r < n; ++r) {
            freq[s[r] - 'A']++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']);

            if (r - l + 1 - maxFreq > k) {
                freq[s[l] - 'A']--;
                l++;
            }
        }

        return n - l;
    }
};

