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

class Solution {
  public:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        return substructure(heights, n, 0, n);
    }

    int substructure(vector<int> &heights, int n, int l, int r) {
        if (l >= r) return 0;

        auto it = min_element(heights.begin() + l, heights.begin() + r);
        int minIdx = it - heights.begin();

        int curr = heights[minIdx] * (r - l);
        int left = substructure(heights, n, l, minIdx);
        int right = substructure(heights, n, minIdx + 1, r);

        return max({curr, left, right});
    }
};
