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

// Time taken: 8 m 26 s
class Solution {
  public:
    int totalFruit(vector<int> &fruits) {
        int n = fruits.size(), res = 0;
        unordered_map<int, int> freq;
        int l = 0;
        for (int r = 0; r < n; ++r) {
            freq[fruits[r]]++;

            while (l <= r && freq.size() > 2) {
                freq[fruits[l]]--;
                if (freq[fruits[l]] == 0) freq.erase(fruits[l]);
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};
