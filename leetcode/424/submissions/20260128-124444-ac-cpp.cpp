/*
 * 424. Longest Repeating Character Replacement
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 17 ms (beats 13.1%)
 * Memory: 10.8 MB (beats 93.4%)
 * Submitted: 2026-01-28 12:44:45 UTC
 * URL: https://leetcode.com/submissions/detail/1899757000/
 */

class Solution {
  public:
    int characterReplacement(string s, int k) {
        int n = s.size(), l = 0, best = 0;
        vector<int> freq(26, 0);

        for (int r = 0; r < n; ++r) {
            freq[s[r] - 'A']++;

            auto it = max_element(freq.begin(), freq.end());
            int maxFreq = *it;

            while (l < r && r - l + 1 - maxFreq > k) {
                freq[s[l] - 'A']--;
                l++;

                it = max_element(freq.begin(), freq.end());
                maxFreq = *it;
            }
            best = max(best, r - l + 1);
        }

        return best;
    }
};

