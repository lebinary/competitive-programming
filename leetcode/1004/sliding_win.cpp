#include <algorithm>
#include <cctype>
#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    int longestOnes(vector<int> &nums, int k) {
        int n = nums.size(), res = 0, zeros = 0;

        int l = 0;
        for (int r = 0; r < n; ++r) {
            zeros += nums[r] == 0 ? 1 : 0;

            while (l <= r && zeros > k) {
                zeros -= nums[l] == 0 ? 1 : 0;
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    };
};
