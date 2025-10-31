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

        int half_n = n / 2;
        double half_x = myPow(x, half_n);

        if (n > 0) {
            if (n % 2 == 0)
                return half_x * half_x;
            else
                return x * half_x * half_x;
        } else {
            if (n % 2 == 0)
                return half_x * half_x;
            else
                return 1 / x * half_x * half_x;
        }
    }
};
