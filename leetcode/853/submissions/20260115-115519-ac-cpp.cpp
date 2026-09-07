/*
 * 853. Car Fleet
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 53 ms (beats 42.3%)
 * Memory: 102.1 MB (beats 85.6%)
 * Submitted: 2026-01-15 11:55:20 UTC
 * URL: https://leetcode.com/submissions/detail/1885760800/
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

        int fleetCount = 0; 
        double lastTime = 0;

        for (int i = 0; i < n; ++i) {
            auto &[pos, speed] = cars[i];
            double time = (double)(target - pos) / speed;

            if(time <= lastTime) continue;
            
            lastTime = time;
            fleetCount++;
            
        }

        return fleetCount;
    }
};
