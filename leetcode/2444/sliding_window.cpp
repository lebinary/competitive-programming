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

// Time taken: 1 hr 47 m 58 s. Hints used: 3
class Solution {
  public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK) {
        int n = nums.size();
        long long res = 0;

        unordered_map<int, int> mapMin, mapMax;
        int lmin = 0, lmax = 0;

        for (int r = 0; r < n; ++r) {
            if (nums[r] < minK || nums[r] > maxK) {
                mapMin.clear();
                mapMax.clear();
                lmin = r + 1;
                lmax = r + 1;
                continue;
            }

            mapMax[nums[r]]++;
            mapMin[nums[r]]++;

            while (lmax <= r && mapMax.count(minK) && mapMax.count(maxK)) {
                mapMax[nums[lmax]]--;
                if (mapMax[nums[lmax]] == 0) mapMax.erase(nums[lmax]);
                lmax++;
            }

            if (mapMin.count(minK) && mapMin.count(maxK)) {
                res += lmax - lmin;
            }
        }

        return res;
    }
};
