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
    int jump(vector<int> &nums) {
        int n = nums.size(), l = 0, r = 0, count = 0;

        while (true) {
            if (r >= n - 1) break;

            int furthest = r;
            for (int i = l; i <= r; ++i) {
                furthest = max(furthest, i + nums[i]);
            }

            l = r + 1;
            r = furthest;
            count++;
        }

        return count;
    }
};
