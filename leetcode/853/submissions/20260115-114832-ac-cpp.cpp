/*
 * 853. Car Fleet
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 66 ms (beats 27.1%)
 * Memory: 102.1 MB (beats 86.0%)
 * Submitted: 2026-01-15 11:48:32 UTC
 * URL: https://leetcode.com/submissions/detail/1885756023/
 */

class Solution {
  public:
    int carFleet(int target, vector<int> &position, vector<int> &speed) {
        int n = position.size();
        vector<pair<int, int>> cars(n, pair<int, int>());

        for (int i = 0; i < n; ++i) {
            cars[i] = {position[i], speed[i]};
        }

        sort(cars.rbegin(), cars.rend());

        int fleetCount = 1, lastFleet = 0;
        for (int i = 0; i < n; ++i) {
            auto &[pos, speed] = cars[i];
            auto &[lastPos, lastSpeed] = cars[lastFleet];

            double time = (double)(target - pos) / speed;
            double lastTime = (double)(target - lastPos) / lastSpeed;
            if (time <= lastTime) {
                continue;
            }

            fleetCount++;
            lastFleet = i;
        }

        return fleetCount;
    }
};
