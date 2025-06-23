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

        res.push_back(newInterval);
        if (i == n) {
            return res;
        }

        while (i < n) {
            vector<int> &curr = intervals[i];
            vector<int> &last = res.back();

            if (overlap(last, curr)) {
                last[0] = min(last[0], curr[0]);
                last[1] = max(last[1], curr[1]);
            } else {
                res.push_back(curr);
            }

            i++;
        }

        return res;
    }

    bool overlap(vector<int> interval1, vector<int> interval2) {
        return (interval1[0] <= interval2[0] && interval2[0] <= interval1[1]) || (interval1[0] <= interval2[1] && interval2[1] <= interval1[1]) ||
               (interval2[0] <= interval1[0] && interval1[0] <= interval2[1]) || interval2[0] <= interval1[0] && interval1[0] <= interval2[1];
    }
};
