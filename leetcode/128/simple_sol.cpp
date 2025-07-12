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
    int longestConsecutive(vector<int> &nums) {
        if (nums.size() == 0) return 0;
        unordered_set<int> set(nums.begin(), nums.end());
        unordered_map<int, int> memo;
        int best = 1;

        for (int num : nums) {
            if (set.count(num - 1)) continue;

            int length = 1;
            while (set.count(num + length)) {
                if (memo.count(num + length)) {
                    length += memo[num + length];
                    break;
                }
                length++;
            }

            memo[num] = length;
            best = max(best, length);
        }

        return best;
    }
};
