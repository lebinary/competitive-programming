#include <algorithm>
#include <cctype>
#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
        vector<vector<int>> res;
        multiset<int> active;
        vector<vector<int>> edges;

        for (vector<int> b : buildings) {
            edges.push_back({b[0], b[2], 0});
            edges.push_back({b[1], b[2], 1});
        }
        sort(edges.begin(), edges.end());

        int lastMax = 0;
        for (vector<int> e : edges) {
            int x = e[0], y = e[1], isEnd = e[2];

            if (isEnd == 1)
                active.erase(y);
            else if (isEnd == 0)
                active.insert(y);

            int max = active.empty() ? 0 : *active.rbegin();
            if (max != lastMax) {
                res.push_back({x, max});
                lastMax = max;
            }
        }

        return res;
    }
};
