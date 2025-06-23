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
        int n = intervals.size(), i = 0;
        int newS = newInterval[0], newE = newInterval[1];
        vector<vector<int>> res;

        while (i < n && intervals[i][1] < newS) {
            res.push_back(intervals[i++]);
        }

        // case 1: reached the end
        if (i == n) {
            res.push_back(newInterval);
            return res;
        }

        if ((intervals[i][0] <= newS && newS <= intervals[i][1]) || (intervals[i][0] <= newE && newE <= intervals[i][1])) {
            // case 2: overlap
            cout << i << endl;
            res.push_back({min(intervals[i][0], newS), max(intervals[i][1], newE)});
        } else {
            // case 3: no overlap
            res.push_back(newInterval);
        }

        while (i < n) {
            vector<int> &last = res.back();
            if (last[0] <= intervals[i][0] && intervals[i][0] <= last[1]) {
                last[1] = max(last[1], intervals[i][1]);
            } else {
                res.push_back(intervals[i]);
            }

            i++;
        }

        return res;
    }
};
