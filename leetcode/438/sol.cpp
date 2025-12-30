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
        int match = 26, n = s.size(), m = p.size();
        vector<int> res, subS(26, 0), subP(26, 0);

        for (int i = 0; i < m; ++i) {
            int j = p[i] - 'a';
            subP[j]++;
            if (subS[j] == subP[j] - 1) match--;
        }

        for (int r = 0; r < n; ++r) {
            int ri = s[r] - 'a';
            subS[ri]++;
            if (subS[ri] == subP[ri])
                match++;
            else if (subS[ri] - 1 == subP[ri])
                match--;

            int l = r - m;
            if (l >= 0) {
                int li = s[l] - 'a';
                subS[li]--;
                if (subS[li] == subP[li])
                    match++;
                else if (subS[li] + 1 == subP[li])
                    match--;
            }
            if (match == 26) res.push_back(l + 1);
        }

        return res;
    }
};
