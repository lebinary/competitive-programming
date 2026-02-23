#include <algorithm>
#include <cctype>
#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <random>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    random_device rd;
    vector<vector<int>> ranges;

    Solution(vector<int> &w) {
        int n = w.size();
        int tot = accumulate(w.begin(), w.end(), 0);

        for (int i = 0; i < n; ++i) {
            if (this->ranges.empty()) {
                this->ranges.push_back({1, w[i]});
                continue;
            }

            vector<int> &prev = this->ranges.back();
            this->ranges.push_back({prev[1] + 1, prev[1] + w[i]});
        }
    }

    int pickIndex() {
        int target = rand(1, ranges.back()[1]);
        int l = 0, r = ranges.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (ranges[m][0] <= target && target <= ranges[m][1])
                return m;
            else if (ranges[m][1] < target)
                l = m + 1;
            else
                r = m - 1;
        }

        return -1;
    }

    int rand(int min, int max) {
        mt19937 gen(rd());
        uniform_int_distribution<> dist(min, max);
        return dist(gen);
    }
}
