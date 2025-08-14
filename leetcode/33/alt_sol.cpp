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

            // at LHS, but target is RHS
            if (nums[0] <= nums[m] && target < nums[0]) {
                l = m + 1;
            }
            // at RHS, but target is LHS
            else if (nums[m] <= nums[n - 1] && target > nums[n - 1]) {
                r = m - 1;
            }

            // else do normal binary search
            else {
                if (nums[m] == target) return m;

                // do normal binary search
                if (target > nums[m])
                    l = m + 1;
                else
                    r = m - 1;
            }
        }

        return -1;
    }
};
