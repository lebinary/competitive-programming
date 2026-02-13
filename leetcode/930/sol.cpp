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
    int numSubarraysWithSum(vector<int> &nums, int goal) {
        int n = nums.size(), count = 0, sum = 0;
        vector<int> prefix(n, 0);
        unordered_map<int, int> map;
        map[0] = 1;

        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            prefix[i] += sum;

            if (map.count(prefix[i] - goal)) count += map[prefix[i] - goal];
            map[prefix[i]]++;
        }

        return count;
    }
};
