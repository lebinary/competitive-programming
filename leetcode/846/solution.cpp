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
    bool isNStraightHand(vector<int> &hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;

        sort(hand.begin(), hand.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int groupCount = 0;

        for (int h : hand) {
            while (!pq.empty() && pq.top().second == groupSize) {
                groupCount++;
                pq.pop();
            };

            if (pq.empty()) {
                pq.push({h, 1});
                continue;
            }

            auto [prevH, count] = pq.top();

            if (prevH + 1 == h) {
                pq.pop();
                pq.push({h, count + 1});
            } else {
                pq.push({h, 1});
            }
        }

        while (!pq.empty() && pq.top().second == groupSize) {
            groupCount++;
            pq.pop();
        }

        return groupCount == n / groupSize;
    }
};
