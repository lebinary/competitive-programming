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
        int l = 0, r = n - 1, m = (l + r) / 2;

        while (l <= r) {
            m = (l + r) / 2;

            if (nums[m] == target) return m;

            if (nums[l] < nums[m] && nums[m] < nums[r]) {
                // do normal binary search
                if (target > nums[m])
                    l = m + 1;
                else
                    r = m - 1;
            } else if (nums[l] < nums[m]) {
                if (nums[l] < target && target < nums[m])
                    r = m - 1;
                else
                    l = m + 1;
            } else {
                if (nums[m] < target && target < nums[r])
                    l = m + 1;
                else
                    r = m - 1;
            }
        }

        return -1;
    }
};
