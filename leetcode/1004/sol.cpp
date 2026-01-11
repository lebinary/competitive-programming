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
        int n = nums.size(), count = 0, best = 0;

        int l = 0;
        for (int r = 0; r < n; ++r) {
            if (nums[r] == 0) {
                while (count == k) {
                    if (nums[l] == 0) count--;
                    l++;
                }

                count++;
            }

            best = max(best, r - l + 1);
        }

        return best;
    };
};
