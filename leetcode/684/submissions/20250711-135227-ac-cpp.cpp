/*
 * 684. Redundant Connection
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 14.6 MB (beats 19.9%)
 * Submitted: 2025-07-11 13:52:28 UTC
 * URL: https://leetcode.com/submissions/detail/1694307884/
 */


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
