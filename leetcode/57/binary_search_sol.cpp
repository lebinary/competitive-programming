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
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        int n = intervals.size();
        if (n == 0) return {newInterval};

        int l = 0, r = n, target = newInterval[0];

        while (l < r) {
            int m = (l + r) / 2;

            if (intervals[m][0] < target) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        intervals.insert(intervals.begin() + l, newInterval);

        vector<vector<int>> res;
        for (vector<int> &interval : intervals) {
            if (res.empty() || res.back()[1] < interval[0]) {
                res.push_back(interval);
            } else {
                res.back()[1] = max(res.back()[1], interval[1]);
            }
        }

        return res;
    }
};
