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
    vector<int> prefixSum;

    Solution(vector<int> &w) {
        int n = w.size();
        this->prefixSum.assign(n, 0);

        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += w[i];
            prefixSum[i] += sum;
        }
    }

    int pickIndex() {
        int target = rand(1, prefixSum.back());
        int l = 0, r = prefixSum.size() - 1;

        while (l < r) {
            int m = l + (r - l) / 2;

            if (prefixSum[l] <= target)
                r = m;
            else
                l = m + 1;
        }

        return l;
    }

    int rand(int min, int max) {
        mt19937 gen(rd());
        uniform_int_distribution<> dist(min, max);
        return dist(gen);
    }
};
