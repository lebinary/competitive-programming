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
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size();
        vector<int> prefix(n + 2, 1);
        vector<int> postfix(n + 2, 1);
        vector<int> res(n, 1);

        for (int i = 1; i < n + 1; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }
        for (int i = n; i > 0; i--) {
            postfix[i] = postfix[i + 1] * nums[i - 1];
        }

        for (int i = 1; i < n + 1; ++i) {
            res[i - 1] = prefix[i - 1] * postfix[i + 1];
        }

        return res;
    }
};
