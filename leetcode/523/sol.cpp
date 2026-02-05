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
    bool checkSubarraySum(vector<int> &nums, int k) {
        int n = nums.size(), sum = 0;
        vector<int> prefix(n, 0);
        unordered_map<int, int> map;
        map[0] = -1;

        for (int j = 0; j < n; ++j) {
            sum += nums[j];
            prefix[j] = sum;
            int key = (prefix[j] % k + k) % k;

            if (map.count(key) && j - map[key] >= 2) return true;

            if (!map.count(key)) map[key] = j;
        }

        return false;
    }
};
