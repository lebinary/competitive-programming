#include <algorithm>
#include <cctype>
#include <climits>
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
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        int n = s.size(), m = t.size(), match = 52;
        pair<int, int> res = {-1, n};
        unordered_map<char, int> sFreq, tFreq;

        for (int i = 0; i < m; ++i) {
            tFreq[t[i]]++;
            if (tFreq[t[i]] == 1) match--;
        }

        int l = 0;
        for (int r = 0; r < n; ++r) {
            sFreq[s[r]]++;
            if (sFreq[s[r]] == tFreq[s[r]]) match++;

            while (match == 52) {
                if (r - l < res.second - res.first) res = {l, r};
                sFreq[s[l]]--;
                if (sFreq[s[l]] + 1 == tFreq[s[l]]) match--;
                l++;
            }
        }
        if (res.first == -1) return "";
        return s.substr(res.first, res.second - res.first + 1);
    }
};
