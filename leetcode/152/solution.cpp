#include <algorithm>
#include <cctype>
#include <climits>
#include <format>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    int maxProduct(vector<int> &nums) {
        int top = 1, bottom = 1, res = INT_MIN;

        for (int num : nums) {
            tie(top, bottom) = make_pair(max({top * num, bottom * num, num}), min({top * num, bottom * num, num}));

            res = max(res, top);
        }

        return res;
    }
};
