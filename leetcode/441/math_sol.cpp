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
        // 1 + 2 + 3 + ... + k + remainder = n
        // 1 + 2 + 3 + ... + k <= n
        // k(k+1) <= 2n
        // k^2 + k <= 2n
        // k^2 + k + 1/4 <= 2n + 1/4
        // (k + 1/2)^2 <= 2n + 1/4
        // k + 1/2 <= sqrt(2n + 1/4)

        return sqrt((double)2 * n + 0.25) - 0.5;
    }
};
