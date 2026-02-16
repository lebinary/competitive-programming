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

// Time taken: 10 m 32 s
class Solution {
  public:
    int maximumUniqueSubarray(vector<int> &nums) {
        int n = nums.size(), best = 0, sum = 0;
        unordered_set<int> uniq;
        int l = 0;

        for (int r = 0; r < n; ++r) {
            while (l <= r && uniq.count(nums[r])) {
                sum -= nums[l];
                uniq.erase(nums[l++]);
            }

            sum += nums[r];
            uniq.insert(nums[r]);
            best = max(best, sum);
        }

        return best;
    }
};
