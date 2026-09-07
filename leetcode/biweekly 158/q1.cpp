#include <cctype>
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
    int maxSumDistinctTriplet(vector<int> &x, vector<int> &y) {
        // y = [6, 5, 4, 3, 2]
        // x = [3, 1, 1, 2, 2]

        int n = x.size(), res = 0;
        vector<pair<int, int>> sorted;

        for (int i = 0; i < n; ++i) {
            sorted.push_back({y[i], x[i]});
        }
        sort(sorted.rbegin(), sorted.rend());

        unordered_set<int> seen;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (count == 3) break;

            int x_i = sorted[i].second, y_i = sorted[i].first;
            if (seen.find(x_i) != seen.end()) continue;
            seen.insert(x_i);

            res += y_i;
            count++;
        }

        return count == 3 ? res : -1;
    }
};
