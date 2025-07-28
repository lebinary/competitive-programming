
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
    int countSubstrings(string s) {
        int n = s.size(), count = 0;

        for (int i = 0; i < n; i++) {
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                count++;
                l--;
                r++;
            }

            l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                count++;
                l--;
                r++;
            }
        }

        return count;
    }
};
