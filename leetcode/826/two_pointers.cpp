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

class Solution {
  public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker) {
        int n = difficulty.size(), m = worker.size(), res = 0;
        vector<vector<int>> jobs(n);
        vector<int> prefixMax(n, INT_MIN);

        for (int i = 0; i < n; ++i) {
            jobs[i] = {difficulty[i], profit[i]};
        }

        sort(jobs.begin(), jobs.end(), [&](auto a, auto b) { return a[0] < b[0]; });
        sort(worker.begin(), worker.end());

        int hi = INT_MIN;
        for (int i = 0; i < n; ++i) {
            hi = max(hi, jobs[i][1]);
            prefixMax[i] = hi;
        }

        int i = n - 1;
        for (int j = m - 1; j >= 0; --j) {
            while (i >= 0 && jobs[i][0] > worker[j]) i--;
            if (i == -1) break;
            res += prefixMax[i];
        }

        return res;
    }
};
