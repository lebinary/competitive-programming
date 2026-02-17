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

// Time taken: 10 m 32 s
// Time taken: 1 hr 28 m 55 s
// Hint used: 2
// Attempt: 2
class Solution {
  public:
    int maximizeWin(vector<int> &prizePositions, int k) {
        int n = prizePositions.size(), res = 0;
        vector<vector<int>> intervals;

        int l = 0;
        for (int r = 0; r < n; ++r) {
            while (l <= r && prizePositions[r] - prizePositions[l] > k) {
                l++;
            }

            if (r < n - 1 && prizePositions[r + 1] - prizePositions[l] <= k) continue;
            intervals.push_back({l, r});
        }

        if (intervals.size() == 1) return intervals[0][1] - intervals[0][0] + 1;

        for (int i = 0; i < intervals.size(); ++i) {
            for (int j = i + 1; j < intervals.size(); ++j) {
                int len = 0;
                if (intervals[i][1] >= intervals[j][0]) {
                    len = intervals[j][1] - intervals[i][0] + 1;
                } else {
                    len = intervals[i][1] - intervals[i][0] + 1 + intervals[j][1] - intervals[j][0] + 1;
                }
                res = max(res, len);
            }
        }

        return res;
    }
};
