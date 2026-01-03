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

// Time: 30:47 minutes
// Attempt: 2
class Solution {
  public:
    string clearStars(string s) {
        int n = s.size();
        vector<bool> res(n, true);
        priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> minHeap;

        for (int i = 0; i < n; ++i) {
            if (s[i] != '*')
                minHeap.push({s[i], i * -1});
            else {
                res[i] = false;
                if (!minHeap.empty()) {
                    auto [val, negIdx] = minHeap.top();
                    minHeap.pop();
                    res[-1 * negIdx] = false;
                }
            }
        }

        string resStr = "";
        for (int i = 0; i < n; ++i) {
            if (res[i] == false) continue;
            resStr += s[i];
        }

        return resStr;
    }
};
