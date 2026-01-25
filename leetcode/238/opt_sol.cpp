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
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size(), product = 1, zeroIdx = -1;
        vector<int> res(n, 1);

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                if (zeroIdx == -1)
                    zeroIdx = i;
                else if (zeroIdx > -1 && zeroIdx < INT_MAX)
                    zeroIdx = INT_MAX;
            }

            product *= nums[i] == 0 ? 1 : nums[i];
        }

        for (int i = 0; i < n; ++i) {
            if (zeroIdx > -1 && zeroIdx == i) {
                res[i] = product;
            } else if (zeroIdx > -1) {
                res[i] = 0;
            } else
                res[i] = product / nums[i];
        }

        return res;
    }
};
