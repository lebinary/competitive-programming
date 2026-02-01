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
    int n;
    int minSubArrayLen(int target, vector<int> &nums) {
        this->n = nums.size();
        int best = INT_MAX, l = 0, r = n + 1;

        while (l < r) {
            int m = l + (r - l) / 2;
            if (val(nums, target, m)) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        return l == n + 1 ? 0 : l;
    }

    bool val(vector<int> &nums, int target, int len) {
        if (len == 0) return false;
        int l = 0, tot = 0;
        for (int r = 0; r < n; ++r) {
            tot += nums[r];
            if (r - l + 1 < len) continue;
            if (tot >= target) return true;
            tot -= nums[l++];
        }
        return false;
    }
};
