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
