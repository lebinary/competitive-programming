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
    int maxArea(vector<int> &height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int best = 0;

        while (l < r) {
            best = max(best, min(height[l], height[r]) * (r - l));

            if (height[l] <= height[r])
                l++;
            else
                r--;
        }

        return best;
    }
};
