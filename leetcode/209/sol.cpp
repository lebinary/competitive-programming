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
    int minSubArrayLen(int target, vector<int> &nums) {
        int n = nums.size(), minLen = INT_MAX, l = 0, tot = 0;

        for (int r = 0; r < n; ++r) {
            tot += nums[r];
            while (l <= r && tot >= target) {
                minLen = min(minLen, r - l + 1);
                tot -= nums[l];
                l++;
            }
        }

        return minLen != INT_MAX ? minLen : 0;
    }
};
