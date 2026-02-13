#include <algorithm>
#include <cctype>
#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    int subarraysWithKDistinct(vector<int> &nums, int k) {
        int n = nums.size(), count = 0;
        unordered_set<int> uniq;
        int l = 0;

        for (int r = 0; r < n; ++r) {
            uniq.insert(nums[r]);

            while (l < r && uniq.size() == k) {
                count++;
                uniq.erase(nums[l++]);
            }
            if (l > 0) {
                l--;
                uniq.insert(nums[l]);
            }
        }

        return count;
    }
};
