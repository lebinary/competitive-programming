#include <cctype>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    int countPartitions(vector<int> &nums, int k) {
        /**
        jump game??
        nums = [9,4,1,3,7], k = 4

        valid: currMin < min && abs(max - currMin) <= k ...
        9: -> 4,
            4: -> 1, 3, 7
                1 -> 3, 7
                    3 -> 7
                        7 -> END
                    3 -> END
                    7 -> END
                3 -> 7, END
                    7 -> END
                7 -> END
         */
        int n = nums.size();
        int res = 0;
        queue<vector<int>> q;
        q.push({0, nums[0], nums[0]});

        while (!q.empty()) {
            vector<int> curr = q.front();
            q.pop();

            int i = curr[0], currMin = curr[1], currMax = curr[2];

            for (int j = i + 1; j <= n; ++j) {
                if (j == n) {
                    res++;
                    break;
                }
                if (j == i + 1) {
                    q.push({j, nums[j], nums[j]});
                    currMin = min(currMin, nums[j]);
                    currMax = max(currMax, nums[j]);
                    continue;
                }

                if (nums[j] < currMin && abs(currMax - nums[j]) <= k) {
                    q.push({j, nums[j], currMax});
                    currMin = nums[j];
                } else if (nums[j] > currMax && abs(nums[j] - currMin) <= k) {
                    q.push({j, currMin, nums[j]});
                    currMax = nums[j];
                } else if (currMin <= nums[j] && nums[j] <= currMax) {
                    q.push({j, currMin, currMax});
                } else {
                    break;
                }
            }
        }

        return res;
    }
};
