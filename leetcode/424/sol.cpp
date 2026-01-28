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
        int n = s.size(), l = 0, best = 0;
        vector<int> freq(26, 0);

        for (int r = 0; r < n; ++r) {
            freq[s[r] - 'A']++;

            auto it = max_element(freq.begin(), freq.end());
            int maxFreq = *it;

            while (l < r && r - l + 1 - maxFreq > k) {
                freq[s[l] - 'A']--;
                l++;

                it = max_element(freq.begin(), freq.end());
                maxFreq = *it;
            }
            best = max(best, r - l + 1);
        }

        return best;
    }
};
