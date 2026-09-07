/*
 * 1170. Compare Strings by Frequency of the Smallest Character
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 5 ms (beats 40.0%)
 * Memory: 19.7 MB (beats 12.4%)
 * Submitted: 2026-02-01 08:47:34 UTC
 * URL: https://leetcode.com/submissions/detail/1904142821/
 */

class Solution {
  public:
    vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words) {
        vector<int> res;
        vector<int> f1(queries.size()), f2(words.size());
        for (int i = 0; i < queries.size(); ++i) f1[i] = f(queries[i]);
        for (int i = 0; i < words.size(); ++i) f2[i] = f(words[i]);
        sort(f2.begin(), f2.end());

        for (int q : f1) {
            int l = 0, r = f2.size();
            while (l < r) {
                int m = l + (r - l) / 2;
                if (q < f2[m]) {
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

