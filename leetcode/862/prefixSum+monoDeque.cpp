#include <climits>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    int shortestSubarray(vector<int> &nums, int k) {
        int n = nums.size(), res = INT_MAX;

        long long sum = 0;
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            prefix[i + 1] = sum;
        }

        deque<long long> dq;
        for (int j = 0; j < n + 1; ++j) {
            while (!dq.empty() && prefix[dq.back()] > prefix[j]) dq.pop_back();
            dq.push_back(j);

            int lastValidIdx = -1;
            while (!dq.empty() && prefix[j] - prefix[dq.front()] >= k) {
                lastValidIdx = dq.front();
                dq.pop_front();
            }

            if (lastValidIdx != -1) res = min(res, j - lastValidIdx);
        }

        return res == INT_MAX ? -1 : res;
    }
};
