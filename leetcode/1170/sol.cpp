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
    vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words) {
        vector<int> res;
        vector<int> f1(queries.size()), f2(words.size());
        for (int i = 0; i < queries.size(); ++i) f1[i] = f(queries[i]);
        for (int i = 0; i < words.size(); ++i) f2[i] = f(words[i]);
        sort(words.begin(), words.end());

        for (int q : f1) {
            int l = 0, r = f2.size();
            while (l < r) {
                int m = l + (r - l) / 2;
                if (q < f2[m]) {
                    r = m;
                } else {
                    l = m + 1;
                }
            }
            res.push_back(words.size() - l);
        }

        return res;
    }

    int f(string s) {
        int resIdx = INT_MAX;
        vector<int> freq(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            freq[s[i] - 'a']++;
            resIdx = min(resIdx, s[i] - 'a');
        }
        return freq[resIdx];
    }
};
