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
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            if (freq.count(num) == 0) freq[num] = 0;
            freq[num]++;
        }

        vector<pair<int, int>> freqVec(freq.begin(), freq.end());
        sort(freqVec.begin(), freqVec.end(), [](auto &a, auto &b) { return a.second > b.second; });

        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(freqVec[i].first);
        }

        return res;
    }
};
