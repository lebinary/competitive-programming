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
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        vector<int> res;

        for (int i = 0; i < k; ++i) {
            pq.push({nums[i], i});

            if (i == k - 1) res.push_back(pq.top().first);
        }

        for (int i = k; i < n; ++i) {
            while (!pq.empty() && pq.top().second < i - k + 1) pq.pop();
            pq.push({nums[i], i});

            // store res
            res.push_back(pq.top().first);
        }

        return res;
    }
};
