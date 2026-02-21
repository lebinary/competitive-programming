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

// Time taken: 9 m 4 s
// Attempts: 2
class Solution {
  public:
    int findPeakElement(vector<int> &nums) {
        int n = nums.size();

        int l = 0, r = n - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;

            long long leftVal = m - 1 < 0 ? LLONG_MIN : nums[m - 1];
            long long rightVal = m + 1 >= n ? LLONG_MIN : nums[m + 1];

            if (leftVal < nums[m] && nums[m] > rightVal)
                return m;
            else if (nums[m] <= rightVal)
                l = m + 1;
            else
                r = m - 1;
        }

        return -1;
    }
};
