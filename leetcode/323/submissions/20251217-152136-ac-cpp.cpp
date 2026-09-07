/*
 * 323. Number of Connected Components in an Undirected Graph
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 8 ms (beats 24.6%)
 * Memory: 19.3 MB (beats 11.4%)
 * Submitted: 2025-12-17 15:21:36 UTC
 * URL: https://leetcode.com/submissions/detail/1858151175/
 */

class Solution {
  public:
    int countComponents(int n, vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> graph;
        vector<bool> seen = vector<bool>(n, false);
        int count = 0;

        for (vector<int> edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; ++i) {
            if (seen[i]) continue;
            dfs(graph, seen, i);
            count++;
        }

        return count;
    }

    void dfs(unordered_map<int, vector<int>> &graph, vector<bool> &seen, int i) {
        if (seen[i]) return;
        seen[i] = true;
        for (int j : graph[i]) {
            dfs(graph, seen, j);
        }
    }
};
