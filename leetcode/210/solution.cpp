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
    vector<int> res;
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < numCourses; ++i) adj[i] = {};
        for (vector<int> pre : prerequisites) {
            adj[pre[0]].push_back(pre[1]);
        }

        unordered_set<int> seen;
        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(adj, seen, i)) return {};
        }

        return res;
    }

    bool dfs(unordered_map<int, vector<int>> &adj, unordered_set<int> &seen, int i) {
        if (seen.count(i)) return false;
        if (!adj.count(i)) return true;

        seen.insert(i);
        for (int prei : adj[i]) {
            if (!dfs(adj, seen, prei)) return false;
        }

        seen.erase(i);
        adj.erase(i);
        res.push_back(i);
        return true;
    }
};
