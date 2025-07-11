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
    int cycleStart;
    unordered_set<int> cycleSet;
    unordered_set<int> seen;
    unordered_map<int, vector<int>> graph;

  public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        this->cycleStart = -1;

        for (vector<int> &edge : edges) {
            this->graph[edge[0]].push_back(edge[1]);
            this->graph[edge[1]].push_back(edge[0]);
        }

        bool hasCycle = dfs(-1, edges[0][0]);
        if (!hasCycle) return {};

        vector<int> res;
        for (int i = edges.size() - 1; i >= 0; --i) {
            vector<int> edge = edges[i];

            if (cycleSet.count(edge[0]) && cycleSet.count(edge[1])) return edge;
        }

        return {};
    }

    bool dfs(int prev, int curr) {
        if (seen.count(curr)) {
            cycleStart = curr;
            cycleSet.insert(curr);
            return true;
        }
        seen.insert(curr);

        for (int nxt : graph[curr]) {
            if (prev == nxt) continue; // same edge
            if (dfs(curr, nxt)) {
                if (cycleStart != -1) cycleSet.insert(curr); // inside the cycle
                if (cycleStart == curr) cycleStart = -1;     // at the end of the cycle
                return true;
            }
        }

        return false;
    }
};
