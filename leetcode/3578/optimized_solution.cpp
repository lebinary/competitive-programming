#include <cctype>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    int countPartitions(vector<int> &nums, int k) {
        uint mod = 1e9 + 7, n = nums.size(), prefix = 1;
        vector<uint> dp(n + 1, 0);
        dp[0] = 1;

        priority_queue<vector<uint>> maxHeap;
        priority_queue<vector<uint>, vector<vector<uint>>, greater<vector<uint>>> minHeap;

        for (uint l = 0, r = 0; r < n; ++r) {
            uint num = nums[r];
            maxHeap.push({num, r});
            minHeap.push({num, r});

            while (l <= r) {
                // clean the heaps, make sure element that is not in current window isn't ON TOP of the heaps
                while (!maxHeap.empty() && maxHeap.top()[1] < l) maxHeap.pop();
                while (!minHeap.empty() && minHeap.top()[1] < l) minHeap.pop();

                if (maxHeap.empty() || minHeap.empty()) break;
                if (maxHeap.top()[0] - minHeap.top()[0] <= k) break;

                // shrink window
                prefix = (prefix - dp[l++] + mod) % mod;
            }

            dp[r + 1] = (prefix % mod);
            prefix = (prefix % mod) + dp[r + 1];
        }

        return (int)dp[n];
    }
};
