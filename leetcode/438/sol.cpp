#include <algorithm>
#include <cctype>
#include <climits>
#include <format>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size(), match = 26;
        vector<int> sfreq(26, 0), pfreq(26, 0), res;

        for (int i = 0; i < m; ++i) {
            pfreq[p[i] - 'a']++;
            if (pfreq[p[i] - 'a'] == sfreq[p[i] - 'a'])
                match++;
            else if (pfreq[p[i] - 'a'] - 1 == sfreq[p[i] - 'a'])
                match--;
        }

        for (int i = 0; i < n; ++i) {
            sfreq[s[i] - 'a']++;
            if (sfreq[s[i] - 'a'] == pfreq[s[i] - 'a'])
                match++;
            else if (sfreq[s[i] - 'a'] - 1 == pfreq[s[i] - 'a'])
                match--;

            if (i >= m) {
                sfreq[s[i - m] - 'a']--;
                if (sfreq[s[i - m] - 'a'] == pfreq[s[i - m] - 'a'])
                    match++;
                else if (sfreq[s[i - m] - 'a'] + 1 == pfreq[s[i - m] - 'a'])
                    match--;
            }

            if (match == 26) res.push_back(i - m + 1);
        }

        return res;
    }
};
