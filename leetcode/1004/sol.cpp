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
        int n = nums.size(), flipCount = 0, best = 0;
        vector<bool> flipped(n, false);

        int l = 0;
        for (int r = 0; r < n; ++r) {
            if (nums[r] == 0) {
                if (flipCount == k) {
                    while (l < r && !flipped[l]) l++;
                    flipped[l++] = false;
                    flipCount--;
                }

                flipped[r] = true;
                flipCount++;
            }

            best = max(best, r - l + 1);
        }

        return best;
    };
};
