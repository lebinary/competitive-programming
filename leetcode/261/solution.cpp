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
    bool validTree(int n, vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> graph;
        unordered_set<int> seen;

        for (int i = 0; i < n; ++i) graph[i] = vector<int>();
        for (auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        return dfs(graph, seen, -1, 0) && seen.size() == n;
    }

    bool dfs(unordered_map<int, vector<int>> &graph, unordered_set<int> &seen, int prev, int curr) {
        if (seen.find(curr) != seen.end()) return false;
        seen.insert(curr);

        for (int nxt : graph[curr]) {
            if (nxt == prev) continue;
            if (!dfs(graph, seen, curr, nxt)) return false;
        }
        return true;
    }
};
