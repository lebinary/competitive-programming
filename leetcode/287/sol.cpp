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
    int findDuplicate(vector<int> &nums) {
        int slow = 0, fast = 0;

        while (slow == 0 || fast == 0 || slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        int slow2 = 0;
        while (slow == 0 || slow2 == 0 || slow != slow2) {
            slow = nums[slow];
            slow2 = nums[slow2];
        }

        return slow;
    }
};
