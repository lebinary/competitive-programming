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
    int countRangeSum(vector<int> &nums, int lower, int upper) {
        int n = nums.size(), res = 0;
        long long sum = 0;
        vector<long long> prefix(n, 0);
        map<long long, int> map;
        map[0] = 1;

        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            prefix[i] = sum;

            auto it_start = map.lower_bound(prefix[i] - upper), it_end = map.upper_bound(prefix[i] - lower);
            for (auto it = it_start; it != it_end; ++it) {
                res += it->second;
            }

            map[prefix[i]] = map.count(prefix[i]) ? map[prefix[i]] + 1 : 1;
        }
        return res;
    }
};
