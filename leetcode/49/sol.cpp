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
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        int n = strs.size();
        vector<int> freq;
        unordered_map<size_t, vector<string>> resMap;

        for (string s : strs) {
            freq.assign(26, 0);
            for (char c : s) {
                freq[c - 'a']++;
            }
            resMap[hashVec(freq)].push_back(s);
        }

        vector<vector<string>> res;
        for (auto [k, v] : resMap) res.push_back(v);
        return res;
    }

    size_t hashVec(vector<int> vec) {
        size_t hash = 0;
        for (int x : vec) {
            hash = (hash * 31) + x;
        }
        return hash;
    }
};
