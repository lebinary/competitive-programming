/*
 * 261. Graph Valid Tree
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 6 ms (beats 26.8%)
 * Memory: 19.8 MB (beats 5.8%)
 * Submitted: 2025-09-07 06:14:27 UTC
 * URL: https://leetcode.com/submissions/detail/1762317273/
 */


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
