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
    int trap(vector<int> &height) {
        int n = height.size(), res = 0;
        int l = 0, r = n - 1;
        int maxL = height[l], maxR = height[r];

        while (l < r) {
            if (maxL < maxR) {
                res += max(0, maxL - height[l++]);
                maxL = max(maxL, height[l]);
            } else {
                res += max(0, maxR - height[r--]);
                maxR = max(maxR, height[r]);
            }
        }

        return res;
    }
};
