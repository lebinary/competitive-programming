/*
 * 1095. Find in Mountain Array
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 8 ms (beats 26.9%)
 * Memory: 9.8 MB (beats 70.4%)
 * Submitted: 2025-07-09 13:46:20 UTC
 * URL: https://leetcode.com/submissions/detail/1692034379/
 */


class Solution {
  public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // find the top mountain
        int n = mountainArr.length();
        int peak = invariant(mountainArr, 0, n);

        int res = classicIncrease(mountainArr, target, 0, peak);
        if (res == -1) {
            res = classicDecrease(mountainArr, target, peak, n - 1);
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
