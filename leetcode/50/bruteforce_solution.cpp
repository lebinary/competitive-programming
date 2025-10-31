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
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n > 0)
            return x * myPow(x, n - 1);
        else
            return 1 / x * myPow(x, n + 1);
    }
};
