#include <algorithm>
#include <cctype>
#include <climits>
#include <format>
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
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;

        for (vector<int> &itv : intervals) {
            if (!res.empty() && itv[0] <= res.back()[1]) {
                res.back()[1] = max(res.back()[1], itv[1]);
            } else {
                res.push_back(itv);
            }
        }

        return res;
    }
};
