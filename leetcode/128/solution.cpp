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
        int best = 1, n = nums.size();
        unordered_set<int> set(nums.begin(), nums.end());

        for (int num : nums) {
            if (set.empty()) return best;
            if (set.count(num) == 0) continue;
            set.erase(num);

            int count = 1, left = num - 1, right = num + 1;
            while (set.count(left) || set.count(right)) {
                if (set.count(left)) {
                    set.erase(left--);
                    count++;
                }
                if (set.count(right)) {
                    set.erase(right++);
                    count++;
                }
            }

            best = max(best, count);
        }

        return best;
    }
};
