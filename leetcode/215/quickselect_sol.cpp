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
    int findKthLargest(vector<int> &nums, int k) {
        int targetIdx = nums.size() - k;
        return quickSelect(nums, 0, nums.size() - 1, targetIdx);
    }

    int quickSelect(vector<int> &nums, int l, int r, int targetIdx) {
        int p = l;

        for (int i = l; i < r; ++i) {
            if (nums[i] <= nums[r]) {
                swap(nums[i], nums[p]);
                p++;
            }
        }
        swap(nums[p], nums[r]);

        if (p > targetIdx) {
            return quickSelect(nums, l, p - 1, targetIdx);
        } else if (p < targetIdx) {
            return quickSelect(nums, p + 1, r, targetIdx);
        } else
            return nums[p];
    }
};
