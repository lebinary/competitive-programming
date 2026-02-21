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
    int search(vector<int> &nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) return m;

            if ((nums[m] >= nums[0] && target < nums[0]) || nums[m] < nums[0] && target >= nums[0]) {
                if (nums[m] < target) {
                    r = m - 1;
                } else
                    l = m + 1;
            } else {
                if (nums[m] < target) {
                    l = m + 1;
                } else
                    r = m - 1;
            }
        }

        return -1;
    }
};
