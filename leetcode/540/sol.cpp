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

// Time taken: 51 m 14 s
// Attempts: 1
// Hints used: 1
class Solution {
  public:
    int singleNonDuplicate(vector<int> &nums) {
        int n = nums.size();

        int l = 0, r = n - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;
            int leftVal = m - 1 < 0 ? -1 : nums[m - 1];
            int rightval = m + 1 >= n ? -1 : nums[m + 1];

            if (nums[m] != leftVal && nums[m] != rightval) return nums[m];

            int leftSize = nums[m] != leftVal ? m : m - 1;
            if (leftSize % 2 == 0)
                l = m + 1;
            else
                r = m - 1;
        }

        return -1;
    }
};
