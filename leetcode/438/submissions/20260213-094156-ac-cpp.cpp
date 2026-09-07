/*
 * 438. Find All Anagrams in a String
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 1 ms (beats 87.5%)
 * Memory: 11.6 MB (beats 37.7%)
 * Submitted: 2026-02-13 09:41:56 UTC
 * URL: https://leetcode.com/submissions/detail/1917860693/
 */

class Solution {
  public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size(), match = 26;
        vector<int> sfreq(26, 0), pfreq(26, 0), res;

        for(int i = 0; i < m; ++i) {
            pfreq[p[i] - 'a']++;
            if(pfreq[p[i] - 'a'] == sfreq[p[i] - 'a']) match++;
            else if(pfreq[p[i] - 'a'] - 1 == sfreq[p[i] - 'a']) match--;
        }

        for(int i = 0; i < n; ++i) {
            sfreq[s[i] - 'a']++;
            if(sfreq[s[i] - 'a'] == pfreq[s[i] - 'a']) match++;
            else if(sfreq[s[i] - 'a'] - 1 == pfreq[s[i] - 'a']) match--;

            if(i >= m) {
                sfreq[s[i - m] - 'a']--;
                if(sfreq[s[i - m] - 'a'] == pfreq[s[i - m] - 'a']) match++;
                else if(sfreq[s[i - m] - 'a'] + 1 == pfreq[s[i - m] - 'a']) match--;
            }

            if(match == 26) res.push_back(i - m + 1);
        }

        return res;
    }
};
