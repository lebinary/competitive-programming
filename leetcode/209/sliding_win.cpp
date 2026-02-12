#include <algorithm>
#include <cctype>
#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int n = nums.size(), sum = 0, res = INT_MAX;

        int l = 0;
        for (int r = 0; r < n; ++r) {
            sum += nums[r];

            while (l <= r && sum - nums[l] >= target) {
                sum -= nums[l++];
            }

            if (sum >= target) {
                res = min(res, r - l + 1);
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};
