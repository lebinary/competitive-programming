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
    int arrangeCoins(int n) {
        // 1 + 2 + 3 + ... k + remainder = n
        // k(k+1)/2 <= n
        // Frame the problem as: Finding largest k s.t. k(k+1)/2 <= n

        int l = -1, r = n;
        while (l < r) {
            int k = l + (r - l + 1) / 2;
            if (k * (k + 1) <= 2 * n) {
                l = k;
            } else {
                r = k - 1;
            }
        }

        return l;
    }
};
