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
        priority_queue<vector<int>> maxHeap;
        vector<int> res;

        for (int i = 0; i < nums.size(); ++i) {
            maxHeap.push({nums[i], i});

            // initial window, skip
            if (i < k - 1) continue;

            // clean up phase
            while (!maxHeap.empty() && maxHeap.top()[1] < i - k + 1) maxHeap.pop();
            if (maxHeap.empty()) continue; // just formality, its not going to be empty since nums[i] will always be here

            res.push_back(maxHeap.top()[0]);
        }

        return res;
    }
};
