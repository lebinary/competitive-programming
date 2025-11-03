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
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto time : times) {
            graph[time[0]].push_back({time[1], time[2]});
        }

        // dijkstra
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        unordered_map<int, int> wMap;

        while (!pq.empty()) {
            // greedy
            auto [currW, curr] = pq.top();
            pq.pop();

            if (wMap.find(curr) != wMap.end()) continue;
            wMap[curr] = currW;

            // relaxation
            for (auto &[nxt, nxtW] : graph[curr]) {
                if (wMap.find(nxt) == wMap.end()) {
                    pq.push({currW + nxtW, nxt});
                }
            }
        }

        if (wMap.size() != n) return -1;

        int maxTime = 0;
        for (auto &[node, time] : wMap) {
            maxTime = max(maxTime, time);
        }
        return maxTime;
    }
};
