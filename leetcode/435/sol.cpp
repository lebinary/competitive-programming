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
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });

        int n = intervals.size(), res = 0;
        vector<int> &last = intervals[0];
        for (int i = 1; i < n; ++i) {
            vector<int> &curr = intervals[i];
            if (curr[0] < last[1]) {
                res++;
            } else {
                last = curr;
            }
        }

        return res;
    }
};
