#include <algorithm>
#include <cctype>
#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        int n = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (int i = 0; i < n; ++i) {
            int dist = pow(points[i][0], 2) + pow(points[i][1], 2);
            minHeap.push({dist, i});
        }

        vector<vector<int>> res;
        for (int _ = 0; _ < k; ++_) {
            auto [dist, i] = minHeap.top();
            minHeap.pop();

            res.push_back(points[i]);
        }

        return res;
    }
};
