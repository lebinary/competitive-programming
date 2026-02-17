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

// Time taken: 7 m 7 s
// Attempts: 1
class Solution {
  public:
    int numberOfSubarrays(vector<int> &nums, int k) {
        int n = nums.size(), res = 0;
        int oddsMin = 0, oddsMax = 0;
        int lmin = 0, lmax = 0;

        for (int r = 0; r < n; ++r) {
            if (nums[r] % 2 != 0) {
                oddsMax++;
                oddsMin++;
            }

            while (lmax <= r && oddsMax >= k) {
                if (nums[lmax] % 2 != 0) oddsMax--;
                lmax++;
            }

            while (lmin <= r && oddsMin > k) {
                if (nums[lmin] % 2 != 0) oddsMin--;
                lmin++;
            }

            if (oddsMin == k) res += lmax - lmin;
        }

        return res;
    }
};
