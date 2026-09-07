/*
 * 875. Koko Eating Bananas
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 6 ms (beats 74.3%)
 * Memory: 23 MB (beats 58.7%)
 * Submitted: 2026-01-25 08:56:42 UTC
 * URL: https://leetcode.com/submissions/detail/1896294936/
 */

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

