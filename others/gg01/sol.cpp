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
    int findMedian(vector<int> &nums) {
        int n = nums.size();
        long long l = -1e18, r = 1e18;

        while (l < r) {
            long long m = l + (r - l) / 2;
            if (validator(nums, n, m))
                r = m;
            else
                l = m + 1;
        }

        return l;
    };

    bool validator(vector<int> &nums, int n, int cand) {
        int count = 0;
        for (int num : nums) {
            if (num <= cand) count++;
        }
        return count >= (1e10 + 1) / 2;
    }
};
