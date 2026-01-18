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
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        vector<int> sub;

        for (int num : nums) {
            if (sub.empty() || num > sub.back()) {
                sub.push_back(num);
            } else {
                int i = bs(sub, num);
                sub[i] = num;
            }
        }

        return sub.size();
    }

    int bs(vector<int> &arr, int num) {
        int l = 0, r = arr.size();
        while (l < r) {
            int m = l + (r - l) / 2;

            if (arr[m] >= num) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        return l;
    }
};
