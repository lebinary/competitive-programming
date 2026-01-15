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

            if (time <= lastTime) continue;

            lastTime = time;
            fleetCount++;
        }

        return fleetCount;
    }
};
