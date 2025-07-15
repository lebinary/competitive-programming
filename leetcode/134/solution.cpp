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
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();

        for (int i = 0; i < n; ++i) {
            int tank = 0, j = i, count = 0;

            do {
                tank += gas[j];
                if (tank < cost[j]) break;
                tank -= cost[j];

                j = (j + 1) % n;
                count++;
            } while (j != i);
            if (j == i && count == n) return i;
        }

        return -1;
    }
};
