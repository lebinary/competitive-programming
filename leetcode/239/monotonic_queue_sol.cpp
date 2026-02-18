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
        vector<int> res;
        deque<int> dq;

        for (int i = 0; i < n; ++i) {
            while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);

            if (i >= k && dq.front() == i - k) dq.pop_front();

            if (i >= k - 1) res.push_back(nums[dq.front()]);
        }

        return res;
    }
};

/** monotonic queue:
Two properties:
- i1 < i2 < ... < in
- nums[i1] >= nums[i2] >= ... >= nums[in]

[1  3  -1] -3  5  3  6  7   => dq = [1,2]
1  [3  -1 -3]  5  3  6  7   => dq = [1,2,3]
1   3 [-1 -3  5]  3  6  7   => dq = [4]
1  3  -1 [-3  5  3]  6  7   => dq = [4,5]
1  3  -1 -3  [5  3  6]  7   => dq = [6]
1  3  -1 -3  5  [3  6  7]   => dq = [7]
**/
