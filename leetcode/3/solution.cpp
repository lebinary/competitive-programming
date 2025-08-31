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
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, best = 0;
        unordered_set<char> seen;

        for (int r = 0; r < n; ++r) {
            while (seen.count(s[r])) seen.erase(s[l++]);
            seen.insert(s[r]);
            best = max(best, r - l + 1);
        }

        return best;
    }
};
