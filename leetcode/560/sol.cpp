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
    int subarraySum(vector<int> &nums, int k) {
        int n = nums.size(), count = 0, prefixSum = 0;
        unordered_map<int, int> sumFreq;

        for (int i = 0; i < n; ++i) {
            sumFreq[prefixSum]++;

            prefixSum += nums[i];
            if (sumFreq.count(prefixSum - k)) {
                count += sumFreq[prefixSum - k];
            }
        }

        return count;
    }
};
