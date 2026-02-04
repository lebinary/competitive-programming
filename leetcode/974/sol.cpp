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
    int subarraysDivByK(vector<int> &nums, int k) {
        int n = nums.size(), res = 0;
        unordered_map<int, int> map;
        map[0] = 1;

        vector<int> prefix(n, 0);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            prefix[i] = sum;
        }

        for (int i = 0; i < n; ++i) {
            int key = ((prefix[i] % k) + k) % k; // normalize
            if (map.count(key)) res += map[key];
            map[key]++;
        }

        return res;
    }
};
