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
    int characterReplacement(string s, int k) {
        int n = s.size(), l = 0, maxFreq = 0;
        vector<int> freq(26, 0);

        for (int r = 0; r < n; ++r) {
            freq[s[r] - 'A']++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']);

            if (r - l + 1 - maxFreq > k) {
                freq[s[l] - 'A']--;
                l++;
            }
        }

        return n - l;
    }
};
