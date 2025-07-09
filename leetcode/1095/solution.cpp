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

// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation
class MountainArray {
  public:
    int get(int index);
    int length();
};

class Solution {
  public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // find the top mountain
        int n = mountainArr.length();
        int peak = invariant(mountainArr, 0, n);

        int res = classicIncrease(mountainArr, target, 0, peak);
        if (res == -1) {
            res = classicDecrease(mountainArr, target, peak, n - 1);
            cout << res << endl;
        }

        return res;
    }

    int classicIncrease(MountainArray &mountainArr, int target, int l, int r) {
        while (l <= r) {
            int m = (l + r) / 2;

            if (mountainArr.get(m) == target)
                return m;
            else if (mountainArr.get(m) < target)
                l = m + 1;
            else
                r = m - 1;
        }

        return -1;
    }

    int classicDecrease(MountainArray &mountainArr, int target, int l, int r) {
        while (l <= r) {
            int m = (l + r) / 2;
            if (mountainArr.get(m) == target)
                return m;
            else if (mountainArr.get(m) > target)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }

    int invariant(MountainArray &mountainArr, int l, int r) {
        while (l < r) {
            int m = (l + r) / 2;

            if (m + 1 < mountainArr.length() && mountainArr.get(m) < mountainArr.get(m + 1))
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
};
