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
    long long countSubarrays(vector<int> &nums, int minK, int maxK) {
        int n = nums.size();
        long long count = 0;
        int leftBound = -1, lastMin = -1, lastMax = -1;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == minK) lastMin = i;
            if (nums[i] == maxK) lastMax = i;
            if (nums[i] < minK || nums[i] > maxK) leftBound = i;

            count += max(0, min(lastMin, lastMax) - leftBound);
        }

        return count;
    }
};
