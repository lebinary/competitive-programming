/*
 * 1170. Compare Strings by Frequency of the Smallest Character
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 86 ms (beats 10.0%)
 * Memory: 83.1 MB (beats 5.4%)
 * Submitted: 2026-02-01 08:40:29 UTC
 * URL: https://leetcode.com/submissions/detail/1904137490/
 */

class Solution {
  public:
    vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words) {
        vector<int> res;
        sort(words.begin(), words.end(), [&](string a, string b) { return f(a) < f(b); });

        for (string q : queries) {
            int l = 0, r = words.size();
            while (l < r) {
                int m = l + (r - l) / 2;
                if (f(q) < f(words[m])) {
                    r = m;
                } else {
                    l = m + 1;
                }
            }
            res.push_back(words.size() - l);
        }

        return res;
    }

    int f(string s) {
        int resIdx = INT_MAX;
        vector<int> freq(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            freq[s[i] - 'a']++;
            resIdx = min(resIdx, s[i] - 'a');
        }
        return freq[resIdx];
    }
};

