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
    int minEatingSpeed(vector<int> &piles, int h) {
        int l = 1, r = INT_MIN;
        for (int p : piles) {
            l = min(l, p);
            r = max(r, p);
        };

        while (l < r) {
            int m = l + (r - l) / 2;

            if (validator(piles, m, h)) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        return l;
    }

    bool validator(vector<int> &piles, int speed, int h) {
        int t = 0;
        for (int p : piles) {
            t += (p + speed - 1) / speed;
        }
        return t <= h;
    }
};
