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

// Time taken: Time taken: 11 m 49 s
// Attempts: 1
class Solution {
  public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK) {
        int n = nums.size();
        long long res = 0;

        int lastMinK = -1, lastMaxK = -1;
        int lmin = 0, lmax = 0;

        for (int r = 0; r < n; ++r) {
            if (nums[r] < minK || nums[r] > maxK) {
                lastMinK = lastMaxK = -1;
                lmin = lmax = r + 1;
                continue;
            }

            if (nums[r] == minK) lastMinK = r;
            if (nums[r] == maxK) lastMaxK = r;

            if (lastMinK != -1 && lastMaxK != -1) {
                lmax = min(lastMinK, lastMaxK) + 1;
                res += lmax - lmin;
            }
        }

        return res;
    }
};
