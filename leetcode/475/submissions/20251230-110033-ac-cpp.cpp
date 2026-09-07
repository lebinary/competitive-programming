/*
 * 475. Heaters
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 16 ms (beats 45.0%)
 * Memory: 29.1 MB (beats 68.6%)
 * Submitted: 2025-12-30 11:00:33 UTC
 * URL: https://leetcode.com/submissions/detail/1869305583/
 */

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
