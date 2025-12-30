#include <algorithm>
#include <cctype>
#include <climits>
#include <format>
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
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int n = houses.size(), m = heaters.size();
        int l = 0, r = max(houses[n - 1], heaters[m - 1]) - min(houses[0], heaters[0]);

        while (l < r) {
            int m = l + (r - l) / 2;

            if (validator(houses, heaters, m)) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        return l;
    }

    bool validator(vector<int> &houses, vector<int> &heaters, int radius) {
        int i = 0;
        for (int pos : heaters) {
            while (i < houses.size() && houses[i] >= pos - radius && houses[i] <= pos + radius) i++;
            if (i >= houses.size()) return true;
        }
        return false;
    }
};
