#include <algorithm>
#include <cctype>
#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    int numberOfSubstrings(string s) {
        int n = s.size(), res = 0;
        unordered_map<char, int> freq;
        int l = 0;

        for (int r = 0; r < n; ++r) {
            freq[s[r]]++;
            while (l <= r && freq.size() >= 3) {
                freq[s[l]]--;
                if (freq[s[l]] == 0) freq.erase(s[l]);
                l++;
            }

            if (freq.size() < 3) res += l;
        }

        return res;
    }
};
