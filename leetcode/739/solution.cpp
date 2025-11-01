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
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        int n = temperatures.size();
        vector<vector<int>> stack;
        vector<int> res = vector<int>(n, 0);

        for (int j = 0; j < temperatures.size(); ++j) {
            int curr = temperatures[j];

            while (stack.size() > 0 && curr > stack.back()[0]) {
                int i = stack.back()[1];
                stack.pop_back();
                res[i] = j - i;
            }

            stack.push_back({curr, j});
        }

        return res;
    }
};
