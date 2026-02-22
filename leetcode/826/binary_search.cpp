#include <algorithm>
#include <cctype>
#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// Time taken: 1 hr 4 m 17 s
// Attempts: 3
class Solution {
  public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker) {
        int n = difficulty.size(), m = worker.size(), res = 0;
        vector<pair<int, int>> jobs(n);
        vector<int> prefixMaxProfit(n);

        for (int i = 0; i < n; ++i) jobs[i] = {difficulty[i], profit[i]};

        sort(jobs.begin(), jobs.end(), [&](auto a, auto b) { return a.first < b.first; });

        int hi = INT_MIN;
        for (int i = 0; i < n; ++i) {
            hi = max(hi, jobs[i].second);
            prefixMaxProfit[i] = hi;
        };

        for (int i = 0; i < m; ++i) {
            int l = -1, r = n - 1;

            while (l < r) {
                int m = l + (r - l + 1) / 2;

                if (jobs[m].first <= worker[i])
                    l = m;
                else
                    r = m - 1;
            }

            if (l == -1) continue;
            res += prefixMaxProfit[l];
        }

        return res;
    }
};
