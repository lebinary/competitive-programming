/*
 * 851. Loud and Rich
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 14 ms (beats 48.8%)
 * Memory: 47.7 MB (beats 48.9%)
 * Submitted: 2026-03-18 14:45:05 UTC
 * URL: https://leetcode.com/submissions/detail/1952184553/
 */

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size(), m = richer.size();
        vector<int> res(n, -1);
        unordered_map<int, pair<int, int>> dp;
        
        unordered_map<int, vector<int>> graph;
        for(vector<int>& r : richer) {
            graph[r[1]].push_back(r[0]);
            if(!graph.count(r[0])) graph[r[0]] = vector<int>();
        }

        for(int i = 0; i < n; ++i) {
            auto [val, idx] = dfs(graph, quiet, dp, i);
            res[i] = idx;
        }

        return res;
    }

    pair<int, int> dfs(unordered_map<int, vector<int>>& graph, vector<int>& quiet, unordered_map<int, pair<int, int>>& dp, int i) {
        if(dp.count(i)) return dp[i];

        pair<int, int> res = { quiet[i], i };
        for(int j : graph[i]) {
            pair<int, int> nei = dfs(graph, quiet, dp, j);
            if(nei.first < res.first) res = nei;
        }

        return dp[i] = res;
    }
};

/**
# Approach 1:
For each person, traverse the "richer" graph, find the person with the "least quite"
TC: O(person * (V + E)) ~= n * (n^2 + n^2) = 500 * 2*500^2 = 10^5 < 10^7
SC: O(V + E)
=> TLE. SOL: use dp

# Questions:
Template for directed graph traversal?

**/
