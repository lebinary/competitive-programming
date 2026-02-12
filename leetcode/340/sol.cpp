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
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.size(), res = 0;
        unordered_map<char, int> map;

        int l = 0;
        for (int r = 0; r < n; ++r) {
            map[s[r]]++;

            while (l <= r && map.size() > k) {
                map[s[l]]--;
                if (map[s[l]] == 0) map.erase(s[l]);
                l++;
            }

            if (map.size() <= k) {
                res = max(res, r - l + 1);
            }
        }

        return res;
    }
};
