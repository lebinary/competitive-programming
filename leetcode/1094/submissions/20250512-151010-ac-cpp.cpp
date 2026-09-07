/*
 * 1094. Car Pooling
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 14 MB (beats 94.9%)
 * Submitted: 2025-05-12 15:10:10 UTC
 * URL: https://leetcode.com/submissions/detail/1631990302/
 */

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int L = numeric_limits<int>::max();
        int R = numeric_limits<int>::min();

        for (auto& trip : trips) {
            L = min(L, trip[1]);
            R = max(R, trip[2]);
        }

        int n = (R+1) - L;
        vector<int> history(n, 0);
        for (auto& trip : trips) {
            history[trip[1] - L] += trip[0];
            history[trip[2] - L] -= trip[0];
        }

        int currCap = 0;
        for (int change : history) {
            currCap += change;
            if(currCap > capacity) return false;
        }

        return true;
    }
};
