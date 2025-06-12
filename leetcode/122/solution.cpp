#include <algorithm>
#include <cctype>
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
    int maxProfit(vector<int> &prices) {
        int res = 0, n = prices.size();
        for (int i = 0; i < n - 1; ++i) {
            if (prices[i + 1] > prices[i]) res += prices[i + 1] - prices[i];
        }
        return res;
    }
};
