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

// Time: 12:23 minutes
// Attempt: 1
class Solution {
  public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<pair<int, int>> stack;

        for (int i = 0; i < n; ++i) {
            int val = temperatures[i];
            while (!stack.empty() && stack.top().first < val) {
                auto [preVal, preIdx] = stack.top();
                stack.pop();
                res[preIdx] = i - preIdx;
            }
            stack.push({val, i});
        }

        return res;
    }
};
