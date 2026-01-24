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
        int n = heights.size(), best = 0;
        stack<int> stack;
        stack.push(-1);

        for (int i = 0; i < n; ++i) {
            while (stack.size() > 1 && heights[i] < heights[stack.top()]) {
                int height = heights[stack.top()];
                stack.pop();
                int width = i - stack.top() - 1;
                best = max(best, height * width);
            }
            stack.push(i);
        };

        while (stack.size() > 1) {
            int height = heights[stack.top()];
            stack.pop();
            int width = n - stack.top() - 1;
            best = max(best, height * width);
        }

        return best;
    }
};
