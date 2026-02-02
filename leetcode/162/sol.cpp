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
    int findPeakElement(vector<int> &nums) {
        int n = nums.size();
        return search(nums, n, 0, n);
    }

    int search(vector<int> &nums, int n, int l, int r) {
        if (l >= r) return -1;
        int m = l + (r - l) / 2;

        long long leftNei = m <= 0 ? LLONG_MIN : nums[m - 1];
        long long rightNei = m >= n - 1 ? LLONG_MIN : nums[m + 1];

        if (leftNei < nums[m] && nums[m] > rightNei) return m;

        int idx = search(nums, n, l, m);
        if (idx != -1) return idx;
        return search(nums, n, m + 1, r);
    }
};
