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

// Time taken: 7 m 02 s
// Attempts: 1
class Solution {
  public:
    int numSubarraysWithSum(vector<int> &nums, int goal) {
        int n = nums.size(), res = 0;
        int sumMin = 0, sumMax = 0;
        int lmin = 0, lmax = 0;

        for (int r = 0; r < n; ++r) {
            sumMax += nums[r];
            sumMin += nums[r];

            while (lmax <= r && sumMax >= goal) {
                sumMax -= nums[lmax++];
            }

            while (lmin <= r && sumMin > goal) {
                sumMin -= nums[lmin++];
            }

            if (sumMin == goal) res += lmax - lmin;
        }

        return res;
    }
};
